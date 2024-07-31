#include "StdAfx.h"
#include "ColorString.h"

//------------------------------------------------------------------------------
// CColorString::CColorString
// 
//	This is hte standard constructor 
// 
//	Access: public
// 
//	Args:
//		none
// 
//	Return:
//		none
// 
CColorString::CColorString()
{
	SetStyle();
   SetBackColor();
}

//------------------------------------------------------------------------------
// CColorString::CColorString
// 
//	This is the good, ol' copy constructor. I'm using the assignment 
//    operator for succinctness. 
// 
//	Access: public
// 
//	Args:
//		const CColorString& strRight	=	source of data
// 
//	Return:
//		none
// 
CColorString::CColorString(const CColorString& strRight)
{
   *this = strRight;
}

//------------------------------------------------------------------------------
// CColorString::CColorString
// 
//	This is the overridden constructor; it'll take a constant string. 
// 
//	Access: public
// 
//	Args:
//		LPCTSTR lpszData			   =	text data
//    const DWORD& dwStyle		   =	color/italicization of text
//    const COLORREF& crBackColor=  background color for the text
// 
//	Return:
//		none
// 
CColorString::CColorString(LPCTSTR lpszData, const DWORD& dwStyle /* = 0x00000000 */,
                           const COLORREF& crBackColor /* = 0xFFFFFFFF */)
{
	SetStyle(dwStyle);
   SetBackColor(crBackColor);

	for (UINT i = 0; i < strlen(lpszData); i++)
	{
		Insert(i, lpszData[i]);
	}
}

//------------------------------------------------------------------------------
// CColorString::CColorString
// 
//	This function is used for implicit CString conversions 
// 
//	Access: public
// 
//	Args:
//		const CString& strData	   =  CString to set our string data to
//    const DWORD&   dwStyle     =  color/italicization of text
//    const COLORREF& crBackColor=  background color for the text
// 
//	Return:
//		none
// 
CColorString::CColorString(const CString& strData, const DWORD& dwStyle /* = 0x00000000 */,
                           const COLORREF& crBackColor /* = 0xFFFFFFFF */)
{
	SetStyle(dwStyle);
   SetBackColor(crBackColor);

	for (int i = 0; i < strData.GetLength(); i++)
	{
		Insert(i, strData.GetAt(i));
	}
}

//------------------------------------------------------------------------------
// CColorString::SetStyle
// 
//	The string's style is a combination of its color and whether or not 
//    it's bold, italic, or underlined. The lower three bytes represent the 
//    color, while the upper two bytes use bit-masking to keep track of the 
//    other properties. 
// 
//	Access: public
// 
//	Args:
//		const DWORD& dwStyle /*= 0x00000000*/	=	style to set the object to
// 
//	Return:
//		none
// 
void CColorString::SetStyle(const DWORD& dwStyle /*= 0x00000000*/)
{
	m_dwTextStyle = dwStyle;
}

//------------------------------------------------------------------------------
// CColorString::GetStyle
// 
//	This function simply returns the string's style. 
// 
//	Access: public
// 
//	Args:
//		none
// 
//	Return:
//		DWORD 	=	style of the string
// 
DWORD CColorString::GetStyle(void) const
{
	return (m_dwTextStyle);
}

//------------------------------------------------------------------------------
// CColorString::SetColor
// 
//	This function sets the color of the string. 
// 
//	Access: public
// 
//	Args:
//		const COLORREF& crColor /* = RGB(0, 0, 0) */	=	color to set the string to
// 
//	Return:
//		none
// 
void CColorString::SetColor(const COLORREF& crColor /* = RGB(0, 0, 0) */)
{
	m_dwTextStyle = ((m_dwTextStyle & 0xFF000000) | crColor);
}

//------------------------------------------------------------------------------
// CColorString::GetColor
// 
//	This function simply returns the string's color 
// 
//	Access: public
// 
//	Args:
//		none
// 
//	Return:
//		COLORREF 	=	color of the string
// 
COLORREF CColorString::GetColor(void) const
{
	return (m_dwTextStyle & 0x00FFFFFF);
}

//------------------------------------------------------------------------------
// CColorString::SetBold
// 
//	This function allows the string to be set to either bold or not bold. 
// 
//	Access: public
// 
//	Args:
//		const BOOL& fSetToBold /* = TRUE */	=	whether or not to set the
//															string to bold-face font
// 
//	Return:
//		none
// 
void CColorString::SetBold(const BOOL& fSetToBold /* = TRUE */)
{
	if (fSetToBold)
	{
		m_dwTextStyle |= COLORSTRING_BOLD;
	}
	else
	{
		if (GetBold())
		{
			m_dwTextStyle -= COLORSTRING_BOLD;
		}
	}
}

//------------------------------------------------------------------------------
// CColorString::GetBold
// 
//	This function simply returns whether or not the string is bold. 
// 
//	Access: public
// 
//	Args:
//		none
// 
//	Return:
//		BOOL 	=	TRUE if the string is bold, FALSE if not
// 
BOOL CColorString::GetBold(void) const
{
	return ((m_dwTextStyle & COLORSTRING_BOLD) == COLORSTRING_BOLD);
}

//------------------------------------------------------------------------------
// CColorString::SetUnderlined
// 
//	This function sets the underlined property of the string. 
// 
//	Access: public
// 
//	Args:
//		const BOOL& fSetToUnderlined /* = TRUE */	=	whether or not to have
//                                                 the string underlined
// 
//	Return:
//		none
// 
void CColorString::SetUnderlined(const BOOL& fSetToUnderlined /* = TRUE */)
{
	if (fSetToUnderlined)
	{
		m_dwTextStyle |= COLORSTRING_UNDERLINE;
	}
	else
	{
		if (GetUnderlined())
		{
			m_dwTextStyle -= COLORSTRING_UNDERLINE;
		}
	}
}

//------------------------------------------------------------------------------
// CColorString::GetUnderlined
// 
//	This function simply returns whether or not the string is underlined. 
// 
//	Access: public
// 
//	Args:
//		none
// 
//	Return:
//		BOOL 	=	TRUE if the string is underlined, FALSE if not
// 
BOOL CColorString::GetUnderlined(void) const
{
	return ((m_dwTextStyle & COLORSTRING_UNDERLINE) == COLORSTRING_UNDERLINE);
}

//------------------------------------------------------------------------------
// CColorString::SetItalic
// 
//	This function sets the italic property of the string. 
// 
//	Access: public
// 
//	Args:
//		const BOOL& fSetToItalic = TRUE	=	whether or not to set the string to
//														be underlined
// 
//	Return:
//		none
// 
void CColorString::SetItalic(const BOOL& fSetToItalic /* = TRUE*/)
{
	if (fSetToItalic)
	{
		m_dwTextStyle |= COLORSTRING_ITALIC;
	}
	else
	{
		if (GetItalic())
		{
			m_dwTextStyle -= COLORSTRING_ITALIC;
		}
	}
}

//------------------------------------------------------------------------------
// CColorString::GetItalic
// 
//	This function returns whether or not the string is italicized. 
// 
//	Access: public
// 
//	Args:
//		none
// 
//	Return:
//		BOOL 	=	TRUE if the string is italicized; FALSE otherwise
// 
BOOL CColorString::GetItalic(void) const
{
	return ((m_dwTextStyle & COLORSTRING_ITALIC) == COLORSTRING_ITALIC);
}

//------------------------------------------------------------------------------
// CColorString::SetBackColor
// 
//	This function will allow the user to set the text's back color 
// 
//	Access: public
// 
//	Args:
//		const COLORREF& crBackColor /* = 0xFFFFFFFF */	=	back-color of the text
//                                                       default translates to
//                                                       COLOR_BTNFACE
// 
//	Return:
//		none
// 
void CColorString::SetBackColor(const COLORREF& crBackColor /* = 0xFFFFFFFF */)
{
   m_crBackColor = (crBackColor == 0xFFFFFFFF ? ::GetSysColor(COLOR_BTNFACE) : crBackColor);
}

//------------------------------------------------------------------------------
// CColorString::GetBackColor
// 
//	This function just returns the text's background color 
// 
//	Access: public
// 
//	Args:
//		none
// 
//	Return:
//		COLORREF 	=	value of the text's background color
// 
COLORREF CColorString::GetBackColor(void) const
{
   return (m_crBackColor);
}

//------------------------------------------------------------------------------
// CColorString::operator=
// 
//	This function simply allows simple assignment to be made. Thanks to our 
//    overridden constructor, it'll let us assign CStrings to our 
//    string-value. 
// 
//	Access: public
// 
//	Args:
//		const CColorString& strRight	=	value to assign our string to
// 
//	Return:
//		CColorString& 	=	enable cascaded ='s
// 
CColorString& CColorString::operator=(const CColorString& strRight)
{
	Empty();

	m_dwTextStyle = strRight.m_dwTextStyle;
   m_crBackColor = strRight.m_crBackColor;
	
	for (int i = 0; i < strRight.GetLength(); i++)
	{
		Insert(i, strRight.GetAt(i));
	}

	return (*this);
}
