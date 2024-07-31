#ifndef __8B275C5F687AE08025E4__MENU__HPP__
#define __8B275C5F687AE08025E4__MENU__HPP__

#include <list>
#include <algorithm>
#include <iterator>
#include <functional>

#include "active.hpp"
#include "vgptr.hpp"
#include "button.hpp"

namespace vwf
{
	class CMenu : public CActive
	{
	private:
		terminal::Colour m_Color;

		CMenu();
		std::list<CVGPtr<CButton> > m_Buttons;
		std::list<CVGPtr<CButton> >::iterator m_ButtonIter;
		std::list<CVGPtr<CButton> >::iterator m_CurButton;
	public:
		static CVGPtr<CMenu> create();
		void Show(CVGPtr<CRect> rect);
		void Add(std::string label, CVGPtr<CActionBase> action);
		bool HandleEvent(Event event, CVGPtr<CScreenObject> scrObj);

		bool Enter();
		void Leave();

		~CMenu(void);
	};
}

#endif // __8B275C5F687AE08025E4__MENU__HPP__
