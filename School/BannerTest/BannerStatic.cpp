#include "stdafx.h"
#include "BannerStatic.h"

const int CBannerStatic::MAXSPEED(1000);  
const int CBannerStatic::MAXSPEED_MODIFIER(CBannerStatic::MAXSPEED*10);
const int CBannerStatic::TIMERRESOLUTION(100);
const int CBannerStatic::STEPHEIGHT(250);

//------------------------------------------------------------------------------
// CBannerStatic::CBannerStatic
// 
//   This function is just the standard constructor.
// 
//   Access: public
// 
//   Args:
//      none
// 
//   Return:
//      none
// 
CBannerStatic::CBannerStatic() : CMultiColorStatic()
{
   m_tmScroll = 0;
   m_nTextOut = 0;
   SetWrapText(TRUE);
   SetScrollSpeed(0);
   SetScrollDelay(100);
   SetScrollSize(-1);
   m_hItemCursor = NULL;
   m_hStdCursor = NULL;
   m_pfnItemClick = NULL;
}

//------------------------------------------------------------------------------
// CBannerStatic::~CBannerStatic
// 
//   This is just the destructor; it doesn't do anything [baseclass handles 
//    all memory] 
// 
//   Access: public
// 
//   Args:
//      none
// 
//   Return:
//      none
// 
CBannerStatic::~CBannerStatic()
{

}

//------------------------------------------------------------------------------
// CBannerStatic::SetScrollSpeed
// 
//   This function validates the incoming data; if it's good, then it will 
//    either start or stop the banner depending on the value. 
// 
//   Access: public
// 
//   Args:
//      const int& nSpeed   =   0 will stop the banner; MAXSPEED will be 
//                              the fastest speed allowed
// 
//   Return:
//      none
// 
void CBannerStatic::SetScrollSpeed(const int& nSpeed)
{
   if ((nSpeed < -MAXSPEED) || (nSpeed > MAXSPEED))
   {
      ASSERT(FALSE); // speed must fall in the above range
      return;
   }

   if (nSpeed == 0)
   {
      if (m_tmScroll)
      {
         timeKillEvent(m_tmScroll);
         m_tmScroll = 0;
      }
   }
   else
   {
      m_nBannerSpeed = nSpeed;
      CalculateScrollParameters();
      m_tmScroll = timeSetEvent(GetScrollDelay(), TIMERRESOLUTION, TimerProc, 
                                (DWORD)this, TIME_CALLBACK_FUNCTION);
   }
}

//------------------------------------------------------------------------------
// CBannerStatic::GetScrollSpeed
// 
//   This just returns the current scroll speed. 
// 
//   Access: public
// 
//   Args:
//      none
// 
//   Return:
//      int    =   amount of scroll speed, from 0 to 1000 inclusive
// 
int CBannerStatic::GetScrollSpeed(void) const
{
   return (m_nBannerSpeed);
}

//------------------------------------------------------------------------------
// CBannerStatic::SetWrapText
// 
//   This function modifies whether or not text should wrap when it has all 
//    scrolled off of the banner. 
// 
//   Access: public
// 
//   Args:
//      const BOOL& fWrapText   =   should text wrap when it has scrolled
//                                  off of the banner?
// 
//   Return:
//      none
// 
void CBannerStatic::SetWrapText(const BOOL& fWrapText)
{
   m_fWrapText = fWrapText;
}

//------------------------------------------------------------------------------
// CBannerStatic::GetWrapText
// 
//   This function returns the status of the WrapText flag. 
// 
//   Access: public
// 
//   Args:
//      none
// 
//   Return:
//      BOOL    =   TRUE if text wraps when it scrolls off the banner, FALSE otherwise
// 
BOOL CBannerStatic::GetWrapText(void) const
{
   return (m_fWrapText);
}

void CBannerStatic::SetItemCursor(const UINT& unItemCursor)
{
   if (m_hItemCursor)
   {
      DestroyCursor(m_hItemCursor);
   }
   
   if (unItemCursor)
   {
      m_hItemCursor = LoadCursor(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(unItemCursor));
   }
   else
   {
      m_hItemCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
   }
}

void CBannerStatic::SetItemClickProc(PFNBANNERITEMCLICK pfnItemClick)
{
   m_pfnItemClick = pfnItemClick;
}

//==================================================================================================
// protected access follows
//==================================================================================================

//------------------------------------------------------------------------------
// CBannerStatic::SetScrollSize
// 
//   This function sets the amount of pixels that the window should scroll 
//    on every tick of the scroll-timer. 
// 
//   Access: protected
// 
//   Args:
//      const int& nScrollSize   =   amount of pixels to scroll
// 
//   Return:
//      none
// 
void CBannerStatic::SetScrollSize(const int& nScrollSize)
{
   m_nScrollSize = nScrollSize;
}

//------------------------------------------------------------------------------
// CBannerStatic::GetScrollSize
// 
//   This function returns the amount of pixels that the window will scroll 
//    on every scroll-timer tick. 
//   That is this function's intended purpose, anyway. Scrollwindow seems to
//    be doing a stretchblt. If you use m_nScrollSize, the window will scroll
//    faster when its height is large ... but it'll be wider as well.
// 
//   Access: protected
// 
//   Args:
//      none
// 
//   Return:
//      int    =   amount of pixels that the window will scroll on every
//                 timer-tick.
// 
int CBannerStatic::GetScrollSize(void) const
{
   return (GetScrollSpeed() > 0 ? -1 : 1);
//   return (m_nScrollSize);
}

//------------------------------------------------------------------------------
// CBannerStatic::SetScrollDelay
// 
//   This is the actual number of milliseconds that will occur between each 
//    timer-tick. 
// 
//   Access: protected
// 
//   Args:
//      const DWORD& dwScrollDelay   =   ms between each timer-tick
// 
//   Return:
//      none
// 
void CBannerStatic::SetScrollDelay(const DWORD& dwScrollDelay)
{
   m_dwScrollDelay = dwScrollDelay;
}

//------------------------------------------------------------------------------
// CBannerStatic::GetScrollDelay
// 
//   This function will return the number of milliseconds between each 
//    timer-tick. 
// 
//   Access: protected
// 
//   Args:
//      none
// 
//   Return:
//      DWORD    =   ms between each timer-tick
// 
DWORD CBannerStatic::GetScrollDelay(void) const
{
   return (m_dwScrollDelay);
}

//------------------------------------------------------------------------------
// CBannerStatic::CalculateScrollParameters
// 
//   This function uses m_nBannerSpeed to calculate m_dwScrollDelay and 
//    m_nScrollSize. 
// 
//   Access: protected
// 
//   Args:
//      none
// 
//   Return:
//      none
// 
void CBannerStatic::CalculateScrollParameters(void)
{
   //---------------------------------------------------------------------------
   // MAXSPEED_MODIFIER is currently just MAXSPEED * 10; this will result in
   // a scroll delay of no less than 10ms
   //
   m_dwScrollDelay = abs(MAXSPEED_MODIFIER / m_nBannerSpeed);

   m_nScrollSize = (m_nBannerSpeed >= 0 ? -1 : 1);

   int nStepHeight = STEPHEIGHT;
   m_nScrollSize *= ((m_rcBounds.Height() / nStepHeight)+1);
}

//------------------------------------------------------------------------------
// CBannerStatic::FindStringFromPoint
// 
//   This function returns the string that's at the point; this is useful 
//    for detecting mouse input so that the client can be notified as to 
//    which string was clicked on. 
// 
//   Access: protected
// 
//   Args:
//      CPoint point   =   point to test for
// 
//   Return:
//      int    =   index of the string
// 
int CBannerStatic::FindStringFromPoint(CPoint point)
{
   for (int i = 0; i < m_vnStrings.size(); i++)
   {
      if (m_vnStrings.at(i) > point.x)
      {
         return (i-1);
      }

      //--------------------------------------
      // make sure they're on ONLY the last
      // string; make sure you cut the range
      // off at its length
      //
      if (i == (m_vnStrings.size() - 1))
      {
         if ((m_vnStrings.at(i) < m_nTextOut + m_nTextLength) &&
             (point.x < (m_nTextOut + m_nTextLength)))
         {
            return (i);
         }
      }
   }

   return (-1);
}

//------------------------------------------------------------------------------
// CBannerStatic::MakeParentPoint
// 
//   In the event that a mouse-message isn't handled, we have to pass it to 
//    the parent. We can convert our point to an LPARAM via this function; we 
//    use this function as the parameter for LPARAM in PostMessage 
// 
//   Access: protected
// 
//   Args:
//      CPoint point   =   point to convert
// 
//   Return:
//      LPARAM    =   LPARAM to put in PostMessage
// 
LPARAM CBannerStatic::MakeParentPoint(CPoint point)
{
   LPARAM lReturn = 0;

   CWnd* pParent = GetParent();
   ClientToScreen(&point);
   pParent->ScreenToClient(&point);

   lReturn = ((0x0000FFFF & point.x) | (0xFFFF0000 & (point.y << 16)));

   return (lReturn);
}

//------------------------------------------------------------------------------
// CBannerStatic::ScrollBanner
// 
//   This function scrolls the banner and then resets the timer so that the 
//    window may be scrolled again. 
// 
//   Access: protected
// 
//   Args:
//      none
// 
//   Return:
//      none
// 
void CBannerStatic::ScrollBanner(void)
{
   //-----------------------------------------------------------
   // if GetScrollSize isn't 1 or -1, it's stretching the
   // text; no it shouldn't be doing this. GetScrollSize is 
   // just returning 1 or -1 for now until this is addressed
   //
   CPoint ptScroll;
   ptScroll.x = GetScrollSize();
   ptScroll.y = 0;

   //--------------------------------------------------
   // this was an attempt at point conversion in the
   // hopes that the stretching when scrolling by
   // multiple pixels problem would be solved here
   //
   CDC* pDC = GetDC();
   LPtoDP(pDC->m_hDC, &ptScroll, 1);
   pDC->DPtoLP(&ptScroll, 1);
   ReleaseDC(pDC);

   
   ScrollWindow(ptScroll.x, ptScroll.y, m_rcBounds, m_rcBounds);
}

//------------------------------------------------------------------------------
// CBannerStatic::TimerProc
// 
//   Multimedia timers are used for better precision on Windows9x [which has 
//    55ms precision for message based timers]. We just use multimedia timers
//    for frequency of ticks; the message is still handled via the message queue.
//    That is, we just post a message telling the banner to scroll here; we don't
//    actually scroll it ourselves in this function. [which goes along with the
//    documentation that says not to do anything except message-posting and timeFuncs
// 
//   Access: protected
// 
//   Args:
//      UINT uID     =  default
//      UINT uMsg    =  default
//      DWORD dwUser =  default 
//      DWORD dw1    =  default 
//      DWORD dw2    =  default 
// 
//   Return:
//      none
// 
void CALLBACK CBannerStatic::TimerProc(UINT uID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
{
   CBannerStatic* pBanner = (CBannerStatic*)dwUser;

   if (::IsWindow(pBanner->m_hWnd))
   {
      pBanner->PostMessage(WM_TIMER, uID, 0);
   }
}

//------------------------------------------------------------------------------
// CBannerStatic::PreSubclassWindow
// 
//   This function is used to initialize everything. We want to make sure 
//    that our standard cursor is an arrow. 
// 
//   Access: protected
// 
//   Args:
//      none
// 
//   Return:
//      none
// 
void CBannerStatic::PreSubclassWindow(void)
{
   CMultiColorStatic::PreSubclassWindow();

   SetScrollSpeed(0);
   m_hStdCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
   m_hItemCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
}

BEGIN_MESSAGE_MAP(CBannerStatic, CMultiColorStatic)
   ON_WM_TIMER()
   ON_WM_PAINT()
   ON_WM_SIZE()
   ON_WM_LBUTTONDOWN()
   ON_WM_LBUTTONUP()
   ON_WM_MBUTTONDOWN()
   ON_WM_MBUTTONUP()
   ON_WM_RBUTTONDOWN()
   ON_WM_RBUTTONUP()
   ON_WM_SETCURSOR()
   ON_WM_MOUSEMOVE()
   ON_WM_DESTROY()
END_MESSAGE_MAP()

//------------------------------------------------------------------------------
// CBannerStatic::OnTimer
// 
//   When we get the timer message [called by TimerProc], we change where we 
//    output the text at and we call ScrollWindow.
// 
//   Access: protected
// 
//   Args:
//      UINT nIDEvent   =   default
// 
//   Return:
//      none
// 
void CBannerStatic::OnTimer(UINT nIDEvent)
{
   if (nIDEvent == m_tmScroll)
   {
      if (GetNumStrings() > 0)
      {
         if (GetWrapText())
         {
            //-----------------------------------------------------------
            // if text wraps in this control ... if it goes off the left
            // side, it'll start over on the right side again
            //
            if (GetScrollSpeed() > 0)
            {
               if ((--m_nTextOut + m_nTextLength) < m_rcBounds.left)
               {
                  m_nTextOut = m_rcBounds.right;
               }
            }
            else if (GetScrollSpeed() < 0)
            {
               if ((++m_nTextOut) > m_rcBounds.right)
               {
                  m_nTextOut = m_rcBounds.left - m_nTextLength;

                  //------------------------------------------------------
                  // on WINNT4 SP6 VC++ 6.0 SP3, this was necessary.
                  // Nothing would ever scroll back around the next time
                  //
                  Invalidate();
               }
            }
         }

         ScrollBanner();
      }

      m_tmScroll = timeSetEvent(GetScrollDelay(), TIMERRESOLUTION, TimerProc, 
                                (DWORD)this, TIME_CALLBACK_FUNCTION);

   }
   else
   {
      CMultiColorStatic::OnTimer(nIDEvent);
   }
}

//------------------------------------------------------------------------------
// CBannerStatic::OnPaint
// 
//   This function does the exact same thing as the base class but also adds 
//    text length. A more elegant method could be devised. 
// 
//   Access: protected
// 
//   Args:
//      none
// 
//   Return:
//      none
// 
void CBannerStatic::OnPaint()
{
   CPaintDC dc(this);
      
   CRect rcBounds = m_rcBounds;      
   rcBounds.left = m_nTextOut;

   //------------------------------------------------------
   // do the background and make sure that we don't
   // paint outside of our client area
   //
   dc.FillRect(m_rcBounds, &m_brBackGround);
   dc.IntersectClipRect(m_rcBounds); 

   m_nTextLength = 0;
   m_vnStrings.clear();

   //------------------------------------------------------
   // draw each string with its own font
   //
   for (int i = 0; i < m_astrData.GetSize(); i++)
   {
      CColorString* pstrCurrent = reinterpret_cast<CColorString*>(m_astrData.GetAt(i));
      TEXTMETRIC    stFontMetrics;
      SIZE          stSize;

      DetermineFont(pstrCurrent);

		//---------------------------------------------------
		// set up the drawing attributes
		//
      dc.SelectObject(&m_ftText)->DeleteObject();
		if (pstrCurrent->GetBackColor() == ::GetSysColor(COLOR_BTNFACE))
      {
         dc.SetBkColor(m_crBackColor);
      }
      else
      {
         dc.SetBkColor(pstrCurrent->GetBackColor());
      }
		dc.SetTextColor(pstrCurrent->GetColor());
		dc.GetOutputTextMetrics(&stFontMetrics);

      GetTextExtentPoint32(dc.GetSafeHdc(), *pstrCurrent, pstrCurrent->GetLength(), &stSize);
				
		//---------------------------------------------------
		// do the drawing and update the position-dependent
      // stuff
		//	
      dc.DrawText(*pstrCurrent, rcBounds, DT_LEFT);
      rcBounds.left += stSize.cx + stFontMetrics.tmOverhang;
      m_vnStrings.push_back(m_nTextOut + m_nTextLength);
      m_nTextLength += stSize.cx + stFontMetrics.tmOverhang;
   }
}

//------------------------------------------------------------------------------
// CBannerStatic::OnSize
// 
//   When the window is sized, we calculate the scroll parameters [if we get 
//    higher, it's possible that we should start scrolling faster] and
//    repaint. 
// 
//   Access: protected
// 
//   Args:
//      UINT nType   =   default
//      int cx       =   default 
//      int cy       =   default 
// 
//   Return:
//      none
// 
void CBannerStatic::OnSize(UINT nType, int cx, int cy)
{
   CMultiColorStatic::OnSize(nType, cx, cy);
   CalculateScrollParameters();
   Invalidate();
}

void CBannerStatic::OnLButtonDown(UINT nFlags, CPoint point)
{
   int nString = FindStringFromPoint(point);
   if (nString != -1)
   {
      // do the callback
      if (m_pfnItemClick)
      {
         m_pfnItemClick(GetParent()->GetSafeHwnd(), nString, GetSafeHwnd());
         return;
      }
   }

   //---------------------------------------------------
   // this will get called if there is no callback
   //
   GetParent()->PostMessage(WM_LBUTTONDOWN, nFlags, MakeParentPoint(point));
}

void CBannerStatic::OnLButtonUp(UINT nFlags, CPoint point)
{
   GetParent()->PostMessage(WM_LBUTTONUP, nFlags, MakeParentPoint(point));
}

void CBannerStatic::OnMButtonDown(UINT nFlags, CPoint point)
{
   GetParent()->PostMessage(WM_MBUTTONDOWN, nFlags, MakeParentPoint(point));
}

void CBannerStatic::OnMButtonUp(UINT nFlags, CPoint point)
{
   GetParent()->PostMessage(WM_MBUTTONUP, nFlags, MakeParentPoint(point));
}

void CBannerStatic::OnRButtonDown(UINT nFlags, CPoint point)
{
   GetParent()->PostMessage(WM_RBUTTONDOWN, nFlags, MakeParentPoint(point));
}

void CBannerStatic::OnRButtonUp(UINT nFlags, CPoint point)
{
   GetParent()->PostMessage(WM_RBUTTONUP, nFlags, MakeParentPoint(point));
}

//------------------------------------------------------------------------------
// CBannerStatic::OnSetCursor
// 
//   We need this function so that we can set the cursor if the user drags 
//    the mouse on a string. In this way, we can change the cursor as if the 
//    string is a hyperlink or something like that. 
// 
//   Access: protected
// 
//   Args:
//      CWnd* pWnd     =   default
//      UINT nHitTest  =   default
//      UINT message   =   default
// 
//   Return:
//      BOOL    =   TRUE if the message is handled, FALSE otherwise
// 
BOOL CBannerStatic::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
   if (FindStringFromPoint(m_ptCursor) != -1)
   {
      ::SetCursor(m_hItemCursor);
      return (TRUE);
   }
   else
   {
      ::SetCursor(m_hStdCursor);
      return (TRUE);
   }
}

//------------------------------------------------------------------------------
// CBannerStatic::OnMouseMove
// 
//   We use this to keep track of the cursor position. 
// 
//   Access: protected
// 
//   Args:
//      UINT nFlags    =   default
//      CPoint point   =   default
// 
//   Return:
//      none
// 
void CBannerStatic::OnMouseMove(UINT nFlags, CPoint point)
{
   m_ptCursor = point;
}

//------------------------------------------------------------------------------
// CBannerStatic::OnDestroy
// 
//   We use this to clean up any cursors that we've loaded; we don't want to 
//    needlessly drain resources. 
// 
//   Access: protected
// 
//   Args:
//      none
// 
//   Return:
//      none
// 
void CBannerStatic::OnDestroy()
{
   if (m_hItemCursor)
   {
      DestroyCursor(m_hItemCursor);
   }

   if (m_hStdCursor)
   {
      DestroyCursor(m_hStdCursor);
   }
}