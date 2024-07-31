/* Terminalhanterare f�r *:85 HT2002                     */
/* Av Jozef Swiatycki                                    */

#ifndef _TERMINAL_STAR85_H
#define _TERMINAL_STAR85_H

#include <vector>
#include <iostream>
#include <string>

namespace terminal_star85 {

// F�ljande struct Event returneras av terminal::getNextEvent()
// whereX och whereY �r kolumn- och radnr
// what �r ett v�rde av typen terminal::Keycodes motsvarande ASCII-koden 
// f�r styr- och skrivbara tecken eller en funktionstangentkod enligt 
// terminal::Keycodes (se nedan)

  struct Event; // Deklaration av Event efter deklarationen av terminal

  class terminal{
  public:
    terminal();             // Initierar terminalf�nstret
    ~terminal();            // �terst�ller terminalf�nstret
    Event getNextEvent();   // Returnerar Event f�r n�sta tangenttryckning
    void clrscr();          // Blankst�ller sk�rmen
    void clreod();          // Blankst�ller resten av sk�rmen fr�n mark�ren
    void clrbod();          // Blankst�ller b�rjan av sk�rmen till mark�ren
    void clrln();           // Blankst�ller raden d�r mark�ren �r
    void clreol();          // Blankst�ller resten av raden fr�n mark�ren
    void clrbol();          // Blankst�ller b�rjan av raden till mark�ren
    void curmove(int x, int y);  // Flyttar mark�ren till kolumn x, rad y
    void chscroll(int x, int y); // �ndrar scrollregionen till x till y
    void curdown(int n=1);  // Flyttar mark�ren n rader ner
    void curleft(int n=1);  // Flyttar mark�ren n positioner till v�nster
    void curright(int n=1); // Flyttar mark�ren n positioner till h�ger
    void curup(int n=1);    // Flyttar mark�ren n rader upp
    void curget(int&, int&);// Ger kolumn, rad d�r mark�ren befinner sig
    void inschar(char c);   // S�tter in c vid mark�ren
    void insstr(const char *);// S�tter in str�ngen vid mark�ren
    void inslines(int n=1); // S�tter in n tomma rader
    void delchar(int n=1);  // Bort tkn h�ger om mark�ren
    void clrchrs(int n=1);  // Blankst�ller n tecken fom mark�ren
    void dellines(int n=1); // Tar bort n rader fr�n aktuell rad
    void scrollup(int n=1); // Scrollar scrollregionen upp n rader
    void scrolldown(int n=1); // Scrollar scrollregionen ner n rader
    void savecur();         // Spara mark�rpositionen
    void restcur();         // �terst�ll senast sparade mark�rpositionen
    void bold();            // Efterf�ljande utskrifter med fet stil
    void reverse();         // Efterf�ljande utskrifter med omv�nd f�rg
    void underline();       // Efterf�ljande utskrifter understrukna
    void normal();          // Efterf�ljande utskrifter med normal stil
    
    enum Colour {Black, Red, Green, Yellow, Blue, Magenta, 
		 Cyan, White, DefColour=9};
    void fgcolour(Colour colr); // Efterf�ljande text i angiven f�rg
    void bgcolour(Colour colr); // Efterf�ljande bakgrund i angiven f�rg
    
    void horline(int row, int fcol, int tcol); // Ritar horisontell linje
    void verline(int col, int frow, int trow); // Ritar vertikal linje
    void box(int a, int b, int c, int d);      // Ritar en rektangel
    void table(int x, int y, std::vector<int> rows, std::vector<int> cols); 
    // Ritar en tabell: x anger startkolumnen, y anger startraden, ...
    // ..rows anger antalet sk�rmrader f�r varje tabellrad, ...
    // ..cols anger antalet sk�rmkolumner f�r varje tabellkolumn, ...
    // ..b�de rows och cols anges exklusive ramen
    
    int height();           // Returnerar terminalf�nstrets h�jd i rader
    int width();            // Returnerar terminalf�nstrets bredd i kolumner
    bool changed();         // Anger om f�nstrets storlek har �ndrats
                            
    void onresize(void (*func)()); // Installerar func som resize-funktion
    void setsize(int height, int width); // S�tter f�nsterstorleken
    
    static std::string version();      // Returnerar versionsnummer

    enum Keycodes {  // *** Kontrolltecken
      NULLchar, CTRLspace = 0,
      CTRLa, 
      CTRLb, 
      CTRLc, // Avbryter exekvering, kan ej f�ngas upp
      CTRLd, 
      CTRLe, 
      CTRLf, 
      CTRLg, BELL = 7,
      CTRLh, BACKSPACE = 8,
      CTRLi, TAB = 9,
      CTRLj, NEWLINE = 10,
      CTRLk, 
      CTRLl, 
      CTRLm, RETURN = 13, ENTER = 13,
      CTRLn, 
      CTRLo, // Kan ej f�ngas upp
      CTRLp,
      CTRLq, // Kan ej f�ngas upp
      CTRLr, 
      CTRLs, // Stoppar datafl�det, kan ej f�ngas upp
      CTRLt, 
      CTRLu, 
      CTRLv,
      CTRLw,
      CTRLx,
      CTRLy,
      CTRLz, // L�gger processen i bakgrunden, kan ej f�ngas upp
      ESC,   // Kan ej f�ngas upp
      
      DELkey=127, RUBOUT=127,

      // *** Funktionstangenter
      F1=256, 
      F2,	   
      F3,     
      F4,     
      F5,     
      F6, 
      F7, 
      F8, 
      F9, 
      F10, 
      F11,
      F12,
      F13, 
      F14,
      Helpkey, 
      Executekey, 
      F17, 
      F18, 
      F19, 
      F20,
      Homekey, 
      Insertkey, 
      Deletekey, 
      Endkey, 
      Pageupkey, 
      Pagedownkey, 
      Uparrowkey, 
      Downarrowkey, 
      Leftarrowkey, 
      Rightarrowkey,
      // Tangenter p� Numeric Key Pad
      PF1, 
      PF2, 
      PF3, 
      PF4, 
      NKPmult,
      NKPplus,
      NKPdiv,
      NKP0, 
      NKP1, 
      NKP2, 
      NKP3, 
      NKP4, 
      NKP5, 
      NKP6, 
      NKP7, 
      NKP8, 
      NKP9, 
      NKPminus, 
      NKPcomma,
      NKPpoint, 
      NKPEnter
    };

  private:
    terminal(const terminal&){}     // F�r att f�rhindra kopiering
    static bool exists;             // F�r att kolla om ett objektt redan finns
  };
  
  // structen Event som returneras av terminal::getNextEvent()
  struct Event {
    int whereX, whereY;           // Koordinater f�r h�ndelsen (kol, rad)
    terminal::Keycodes what;      // H�ndelsens tangentkod
  };
  
  // Implementering av manipulatorer f�r terminalen, s� att 
  // medlemsfunktioner kan anropas med hj�lp av �verlagringar av operator<<
  
  struct tmanip2{
    terminal& (*f)(terminal&, int, int);
    int x,y;
    tmanip2(terminal& (*ff)(terminal&,int,int),int xx,int yy):
      f(ff),x(xx),y(yy){}
  };
  
  struct tmanip1{
    terminal& (*f)(terminal&, int);
    int x;
    tmanip1(terminal& (*ff)(terminal&, int),int xx):f(ff),x(xx){}
  };
  
  struct tmanipc{
    terminal& (*f)(terminal&, char);
    char c;
    tmanipc(terminal& (*ff)(terminal&, char), char cc):f(ff),c(cc){}
  };
  
  struct tmanips{
    terminal& (*f)(terminal&, const char*);
    const char *str;
    tmanips(terminal& (*ff)(terminal&, const char *), const char* s):
      f(ff),str(s) {}
  };
  
  tmanip2 curmove(int x, int y);
  tmanip2 chscroll(int x, int y);
  tmanip1 fgcolour(int x);
  tmanip1 bgcolour(int x);
  tmanip1 curright(int n=1);
  tmanip1 curleft(int n=1);
  tmanip1 curdown(int n=1);
  tmanip1 curup(int n=1);
  tmanip1 inslines(int n=1);
  tmanip1 delchar(int n=1);
  tmanip1 clrchrs(int n=1);
  tmanip1 dellines(int n=1);
  tmanip1 scrollup(int n=1);
  tmanip1 scrolldown(int n=1);
  tmanipc inschar(char c);
  tmanips insstr(const char *str);
  terminal& clrscr(terminal& t);
  terminal& clreod(terminal& t);
  terminal& clrbod(terminal& t);
  terminal& clreol(terminal& t);
  terminal& clrbol(terminal& t);
  terminal& clrln(terminal& t);
  terminal& normal(terminal& t);
  terminal& bold(terminal& t);
  terminal& reverse(terminal& t);
  terminal& underline(terminal& t);
  terminal& savecur(terminal& t);
  terminal& restcur(terminal& t);
  
  
  terminal& operator<<(terminal& term, terminal& (*f)(terminal&));
  terminal& operator<<(terminal& term, const tmanip1 m);
  terminal& operator<<(terminal& term, const tmanip2 m);
  terminal& operator<<(terminal& term, const tmanipc m);
  terminal& operator<<(terminal& term, const tmanips m);
  
  template<class TYP>
  terminal& operator<<(terminal& term, const TYP& data){
    std::cout << data << std::flush;
    return term;
  }
  
  terminal& operator<<(terminal& term, const char* data);
  terminal& operator<<(terminal& term, const std::string& data);
  terminal& operator<<(terminal& term, const char data);
  
} // namespace terminal_star85

#endif

  /*********************************************************/
  /* F�ljande rader �r till f�r versionshanteraren RCS     */
  /* Bry er inte om dem                                    */
  /* $Log: terminal.h,v $
   * Revision 2.0  2002/02/11 18:23:16  jozef
   * terminal och hj�lpfunktioner nu i namnrymden terminal_star85
   *
   * Revision 1.9  2001/01/26 16:48:38  jozef
   * Anpassat funktionskoderna till PC-tangentbord
   *
   * Revision 1.8  2000/01/09 12:36:49  jozef
   * Anpassat till MS Windows-versionen.
   * Tagit bort #define DTTERM och #ifdef DTTERM
   * Lagt till specialiseringar av terminal& operator<<(terminal&, const TYP&)
   * f�r tecken-data f�r att m�jligg�ra konverteringar till OEM-teckenkod
   * Lagt till static string terminal::version() f�r att kunna avl�sa vesionsst�mpeln
   *
   * Revision 1.7  1998/12/18 06:32:59  jozef
   * R�ttat en kommentar
   *
   * Revision 1.6  1998/12/18 02:41:34  jozef
   * �ndrat typen f�r Event::what fr�n int till terminal::Keycodes
   *
   * Revision 1.5  1998/12/17 22:15:16  jozef
   * Anpassat till HT98
   *
   * Revision 1.4  1998/01/02 11:25:36  jozef
   * *** empty log message ***
   *
   * Revision 1.3  1997/12/24 15:54:59  jozef
   * - lagt till prefixet z till anrop av termfunktioner
   *   f�r att f�rhindra namnkollisioner med manipulatorer
   * - lagt till dtterm-funktionalitet
   * - lagt till manipulatorer och �verlagringar av operator<<
   * - inkluderat iostream.h och vector
   *
   * Revision 1.1  1997/01/08  04:54:56  jozef
   * Initial revision
   *                                                 */
  /*                 Slut p� versionshanterarrader         */
  /*********************************************************/
  
