#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "f1lib.h"

#define GP3_FILE_TYPE_CRUNCHED_MASK	0x80
#define GP3_FILE_DESC_SIZE			18
#define GP3_FILE_ID					0x853da1be
#define GP3_FILE_CHECKSUM_SIZE		4
#define GP3_FILE_TYPE(t)			((t) & GP3_FILE_TYPE_MASK)
#define GP3_FILE_ISCRUNCHED(t)		((t) & GP3_FILE_TYPE_CRUNCHED_MASK)

#define UNPRINTABLE_CHAR '.'

typedef unsigned char UBYTE;
typedef unsigned short UWORD;
typedef unsigned long ULONG;

typedef struct GP3HEADER
{
	DWORD id;	// GP3_FILE_ID
	BYTE type;
	// Track field only for track specific file
	BYTE track;
	// Fields below only for saved games (session mode valid)
	BYTE num_players;
	BYTE num_linkplayers;	// linked game only
	BYTE unknown2;		// unused
	BYTE unknown3;		// unused
	BYTE session_mode_valid;
	BYTE session_mode;
	BYTE laps_completed;
	BYTE laps_total;
	char desc[GP3_FILE_DESC_SIZE];	// Race leader
} GP3Header;

static unsigned char unprintable_char=UNPRINTABLE_CHAR;

void main(int argc, char *argv[])
{
	FILE *src_file, *dest_file;
	GP3Header *header_buffer;
	UBYTE *dest_buffer, *dest_end, *src_buffer;
	UWORD cs_sum, cs_cycle;
	unsigned int n, real_dest_length, datasize;

	fprintf(stderr, "DecGP3 v1.0 (Aug 2, 2000) by Marc Aarts.\n");
	if (argc != 3)
	{
		fprintf(stderr, "usage: %s <source> <destination>\n", argv[0]);
		exit(1);
    }

    if ((src_file=fopen(argv[1], "rb+"))==NULL)
    {
		fprintf(stderr, "%s: cannot open %s\n", argv[0], argv[1]);
		exit(1);
    }

	if (!(header_buffer = malloc(sizeof(GP3Header))))
	{
		fprintf(stderr, "%s: Out of memory\n", argv[0]);
		exit(1);
	}

	if (fread(header_buffer, 1, sizeof(GP3Header), src_file) !=
		sizeof(GP3Header))
	{
		fprintf(stderr, "%s: error reading header of %s\n", argv[0],
			argv[1]);
			exit(1);
	}

	/* Type checking */
	if (header_buffer->id != GP3_FILE_ID)
	{
		fprintf(stderr, "%s: file %s not a GP3 data file\n",
			argv[0], argv[1]);
		exit(1);
	}

	fprintf(stdout,"File type: ");

	fprintf(stdout," ($%02x)\n", header_buffer->type);
	fprintf(stdout,"Information: `");
	for (n=0; n<GP3_FILE_DESC_SIZE; n++)
		if (isprint(header_buffer->desc[n]))
			putchar(header_buffer->desc[n]);
		else
			putchar(unprintable_char);
	puts("'");

	/* Is it crunched? */
	if (!GP3_FILE_ISCRUNCHED(header_buffer->type))
	{
	  fprintf(stdout,"File is not crunched\n");
	  exit(1);
	}

	if (fseek(src_file, 0, SEEK_END) < 0)
	{
		fprintf(stderr, "%s: seek failed in %s\n", argv[0], argv[1]);
		exit(1);
	}

	if ((datasize = ftell(src_file)) == -1)
	{
		fprintf(stderr, "%s: cannot access %s\n", argv[0], argv[1]);
		exit(1);
	}

	if (datasize <= 0)
	{
		fprintf(stderr, "%s: file %s is empty\n", argv[0], argv[1]);
		exit(1);
	}

	datasize -= sizeof(GP3Header);
	fprintf(stdout,"Source length %d\n", datasize);

	if (fseek(src_file, sizeof(GP3Header), SEEK_SET) < 0)
	{
		fprintf(stderr, "%s: seek failed in %s\n", argv[0], argv[1]);
		exit(1);
	}

	if (!(src_buffer = malloc(datasize)))
	{
		fprintf(stderr, "%s: Out of memory\n", argv[0]);
		exit(1);
	}

	if (!(dest_buffer = malloc(datasize*8)))
	{
		fprintf(stderr, "%s: Out of memory\n", argv[0]);
		exit(1);
	}

	if (fread(src_buffer, 1, datasize, src_file) != datasize)
	{
		fprintf(stderr, "%s: error reading %s\n", argv[0], argv[1]);
		exit(1);
	}

	real_dest_length = GP3_Decrunch(src_buffer, dest_buffer,
		datasize-GP3_FILE_CHECKSUM_SIZE);

	fprintf(stdout,"Length of decrunched file %d\n",
		sizeof(GP3Header) + real_dest_length + GP3_FILE_CHECKSUM_SIZE);

	/* save */

	if ((dest_file=fopen(argv[2], "wb"))==NULL)
	{
		fprintf(stderr, "%s: cannot open %s\n", argv[0], argv[2]);
		exit(1);
	}

	/* write header */
	header_buffer->type &= ~GP3_FILE_TYPE_CRUNCHED_MASK;	/* clr compression bit */
	if (fwrite(header_buffer, 1, sizeof(GP3Header), dest_file) != sizeof(GP3Header))
	{
		fprintf(stderr, "%s: error writing header of %s\n", argv[0], argv[2]);
		exit(1);
	}

	/* calculate checksum */
	cs_sum = cs_cycle = 0;
	GP3_CalcChecksum((UBYTE *) header_buffer, sizeof(GP3Header), &cs_sum, &cs_cycle);
	GP3_CalcChecksum(dest_buffer, real_dest_length, &cs_sum, &cs_cycle);
	dest_end = dest_buffer + real_dest_length;
	*dest_end++ = (UBYTE) (cs_sum & 0xff);
	*dest_end++ = (UBYTE) (cs_sum >> 8);
	*dest_end++ = (UBYTE) (cs_cycle & 0xff);
	*dest_end++ = (UBYTE) (cs_cycle >> 8);

	/* write uncompressed data and checksum */
	if (fwrite(dest_buffer, 1, (int) (dest_end - dest_buffer),
		dest_file) != real_dest_length + GP3_FILE_CHECKSUM_SIZE)
	{
		fprintf(stderr, "%s: error writing %s\n", argv[0], argv[2]);
		exit(1);
	}

	exit(0);
}