#ifndef F1LIB_H
#define F1LIB_H

#ifdef __cplusplus
extern "C" {
#endif

int			GP3_Crunch(unsigned char * src, unsigned char * dest, unsigned int src_length);
int			GP3_Decrunch(unsigned char * src, unsigned char * dest, unsigned int src_length);
void		GP3_CalcChecksum(unsigned char * src, long src_length, unsigned short * sum, unsigned short * cycle);

#ifdef __cplusplus
}	/* extern "C" */
#endif


///////////////////////////////////////////////////////////////////////////////////////////

#endif
