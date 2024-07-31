/* Terminalhanterare för *:85 HT2002                     */
/* Av Jozef Swiatycki                                    */

#ifndef _TERMINAL_STAR85_H
#define _TERMINAL_STAR85_H

#include <vector>
#include <iostream>
#include <string>

namespace terminal_star85 {

// Följande struct Event returneras av terminal::getNextEvent()
// whereX och whereY är kolumn- och radnr
// what är ett värde av typen terminal::Keycodes motsvarande ASCII-koden 
// för styr- och skrivbara tecken eller en funktionstangentkod enligt 
// terminal::Keycodes (se nedan)

  struct Event; // Deklaration av Event efter deklarationen av terminal

  class terminal{
  public:
    terminal();             // Initierar terminalfönstret
    ~terminal();            // Återställer terminalfönstret
    Event getNextEvent();   // Returnerar Event för nästa tangenttryckning
    void clrscr();          // Blankställer skärmen
    void clreod();          // Blankställer resten av skärmen från markören
    void clrbod();          // Blankställer början av skärmen till markören
    void clrln();           // Blankställer raden där markören är
    void clreol();          // Blankställer resten av raden från markören
    void clrbol();          // Blankställer början av raden till markören
    void curmove(int x, int y);  // Flyttar markören till kolumn x, rad y
    void chscroll(int x, int y); // Ändrar scrollregionen till x till y
    void curdown(int n=1);  // Flyttar markören n rader ner
    void curleft(int n=1);  // Flyttar markören n positioner till vänster
    void curright(int n=1); // Flyttar markören n positioner till höger
    void curup(int n=1);    // Flyttar markören n rader upp
    void curget(int&, int&);// Ger kolumn, rad där markören befinner sig
    void inschar(char c);   // Sätter in c vid markören
    void insstr(const char *);// Sätter in strängen vid markören
    void inslines(int n=1); // Sätter in n tomma rader
    void delchar(int n=1);  // Bort tkn höger om markören
    void clrchrs(int n=1);  // Blankställer n tecken fom markören
    void dellines(int n=1); // Tar bort n rader från aktuell rad
    void scrollup(int n=1); // Scrollar scrollregionen upp n rader
    void scrolldown(int n=1); // Scrollar scrollregionen ner n rader
    void savecur();         // Spara markörpositionen
    void restcur();         // Återställ senast sparade markörpositionen
    void bold();            // Efterföljande utskrifter med fet stil
    void reverse();         // Efterföljande utskrifter med omvänd färg
    void underline();       // Efterföljande utskrifter understrukna
    void normal();          // Efterföljande utskrifter med normal stil
    
    enum Colour {Black, Red, Green, Yellow, Blue, Magenta, 
		 Cyan, White, DefColour=9};
    void fgcolour(Colour colr); // Efterföljande text i angiven färg
    void bgcolour(Colour colr); // Efterföljande bakgrund i angiven färg
    
    void horline(int row, int fcol, int tcol); // Ritar horisontell linje
    void verline(int col, int frow, int trow); // Ritar vertikal linje
    void box(int a, int b, int c, int d);      // Ritar en rektangel
    void table(int x, int y, std::vector<int> rows, std::vector<int> cols); 
    // Ritar en tabell: x anger startkolumnen, y anger startraden, ...
    // ..rows anger antalet skärmrader för varje tabellrad, ...
    // ..cols anger antalet skärmkolumner för varje tabellkolumn, ...
    // ..både rows och cols anges exklusive ramen
    
    int height();           // Returnerar terminalfönstrets höjd i rader
    int width();            // Returnerar terminalfönstrets bredd i kolumner
    bool changed();         // Anger om fönstrets storlek har ändrats
                            
    void onresize(void (*func)()); // Installerar func som resize-funktion
    void setsize(int height, int width); // Sätter fönsterstorleken
    
    static std::string version();      // Returnerar versionsnummer

    enum Keycodes {  // *** Kontrolltecken
      NULLchar, CTRLspace = 0,
      CTRLa, 
      CTRLb, 
      CTRLc, // Avbryter exekvering, kan ej fångas upp
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
      CTRLo, // Kan ej fångas upp
      CTRLp,
      CTRLq, // Kan ej fångas upp
      CTRLr, 
      CTRLs, // Stoppar dataflödet, kan ej fångas upp
      CTRLt, 
      CTRLu, 
      CTRLv,
      CTRLw,
      CTRLx,
      CTRLy,
      CTRLz, // Lägger processen i bakgrunden, kan ej fångas upp
      ESC,   // Kan ej fångas upp
      
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
      // Tangenter på Numeric Key Pad
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
    terminal(const terminal&){}     // För att förhindra kopiering
    static bool exists;             // För att kolla om ett objektt redan finns
  };
  
  // structen Event som returneras av terminal::getNextEvent()
  struct Event {
    int whereX, whereY;           // Koordinater för händelsen (kol, rad)
    terminal::Keycodes what;      // Händelsens tangentkod
  };
  
  // Implementering av manipulatorer för terminalen, så att 
  // medlemsfunktioner kan anropas med hjälp av överlagringar av operator<<
  
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
  /* Följande rader är till för versionshanteraren RCS     */
  /* Bry er inte om dem                                    */
  /* $Log: terminal.h,v $
   * Revision 2.0  2002/02/11 18:23:16  jozef
   * terminal och hjälpfunktioner nu i namnrymden terminal_star85
   *
   * Revision 1.9  2001/01/26 16:48:38  jozef
   * Anpassat funktionskoderna till PC-tangentbord
   *
   * Revision 1.8  2000/01/09 12:36:49  jozef
   * Anpassat till MS Windows-versionen.
   * Tagit bort #define DTTERM och #ifdef DTTERM
   * Lagt till specialiseringar av terminal& operator<<(terminal&, const TYP&)
   * för tecken-data för att möjliggöra konverteringar till OEM-teckenkod
   * Lagt till static string terminal::version() för att kunna avläsa vesionsstämpeln
   *
   * Revision 1.7  1998/12/18 06:32:59  jozef
   * Rättat en kommentar
   *
   * Revision 1.6  1998/12/18 02:41:34  jozef
   * Ändrat typen för Event::what från int till terminal::Keycodes
   *
   * Revision 1.5  1998/12/17 22:15:16  jozef
   * Anpassat till HT98
   *
   * Revision 1.4  1998/01/02 11:25:36  jozef
   * *** empty log message ***
   *
   * Revision 1.3  1997/12/24 15:54:59  jozef
   * - lagt till prefixet z till anrop av termfunktioner
   *   för att förhindra namnkollisioner med manipulatorer
   * - lagt till dtterm-funktionalitet
   * - lagt till manipulatorer och överlagringar av operator<<
   * - inkluderat iostream.h och vector
   *
   * Revision 1.1  1997/01/08  04:54:56  jozef
   * Initial revision
   *                                                 */
  /*                 Slut på versionshanterarrader         */
  /*********************************************************/
  
