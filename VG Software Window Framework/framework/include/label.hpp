#ifndef __3BFA69DB9A8919ED032B2__LABEL__HPP__
#define __3BFA69DB9A8919ED032B2__LABEL__HPP__

#include "passive.hpp"
#include "vgptr.hpp"
#include <string>

using namespace std;

namespace vwf
{
	class CLabel : public CPassive
	{
	private:
		string m_Text;
		CLabel(string text);
	public:
		static CVGPtr<CLabel> create(string text);
		void SetText(string text){m_Text=text;};
		string& GetText(){return(m_Text);};
		void Show(CVGPtr<CRect> rect);
		~CLabel(void);
	};
}

#endif // __3BFA69DB9A8919ED032B2__LABEL__HPP__
