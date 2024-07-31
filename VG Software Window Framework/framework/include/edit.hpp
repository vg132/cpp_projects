#ifndef __1658EFAA0A66C216EBAF4__EDIT__HPP__
#define __1658EFAA0A66C216EBAF4__EDIT__HPP__

#include "active.hpp"
#include "vgptr.hpp"
#include <string>

namespace vwf
{
	class CEdit : public CActive
	{
	private:
		int m_CurPos;

		terminal::Colour m_Color;
		std::string m_Text;
		CEdit(void);
		CEdit(std::string str);
	public:
		static CVGPtr<CEdit> create();
		static CVGPtr<CEdit> create(std::string str);
		void Show(CVGPtr<CRect> rect);
		bool Enter();
		void Leave();
		bool HandleEvent(Event event, CVGPtr<CScreenObject> scrObj);
		~CEdit(void);
	};
}

#endif // __1658EFAA0A66C216EBAF4__EDIT__HPP__
