#ifndef __1FBE7862510D6B02CE6E4__FRAME__HPP__
#define __1FBE7862510D6B02CE6E4__FRAME__HPP__

#include <vector>
#include <exception>
#include <stdexcept>

#include "active.hpp"
#include "screenobject.hpp"
#include "vgptr.hpp"
#include "objectdata.hpp"
#include "size.hpp"
#include "focushelp.hpp"
#include "terminal.h"

namespace vwf
{
	class CFrame : public CActive
	{
	private:
		CFrame(CVGPtr<CRect> rect);
		CFrame();

		void DrawScreen();
		void SetFocus();

		std::vector<CVGPtr<CObjectData> > m_ObjectData;
		std::vector<CVGPtr<CObjectData> >::iterator m_ObjectIter;
		std::vector<CVGPtr<CObjectData> >::iterator m_CurrentObjectIter;
	public:
		static CVGPtr<CFrame> create(CVGPtr<CRect> rect);
		static CVGPtr<CFrame> create();
		void AddScreenObject(CVGPtr<CScreenObject> object, CVGPtr<CPoint> pos, CVGPtr<CSize> size);
		void AddScreenObject(CVGPtr<CScreenObject> object, CVGPtr<CRect> rect);
		void RemoveScreenObject(CVGPtr<CScreenObject> object);
		void Show();
		void Hide();
		~CFrame(void);
	};
}

#endif // __1FBE7862510D6B02CE6E4__FRAME__HPP__
