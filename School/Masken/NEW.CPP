#include <conio.h>
#include <ctype.h>
#include <stdio.h>

void main( void )
{
   int ch;

   cputs( "Type 'Y' when finished typing keys: " );
   do
   {
      ch = getch();
      printf("%d",ch);
   } while( ch != 'Y' );

   putch( ch );
   putch( '\r' );    /* Carriage return */
   putch( '\n' );    /* Line feed       */
}
