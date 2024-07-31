#ifndef __6E758EF49FFF8EB92E7B__BUTTON__HPP__
#define __6E758EF49FFF8EB92E7B__BUTTON__HPP__

#include "active.hpp"
#include "vgptr.hpp"
#include <string>
#include <iostream>

using namespace std;

namespace vwf
{
	class CButton : public CActive
	{
	private:
		CButton(string text);
		terminal::Colour m_Color;
		string m_Text;
	public:
		static CVGPtr<CButton> create(string text);
		void Show(CVGPtr<CRect> rect);
		bool Enter();
		void Leave();
		void SetText(string text){m_Text=text;};
		~CButton(void);
	};
}

#endif // __6E758EF49FFF8EB92E7B__BUTTON__HPP__
