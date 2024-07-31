#ifndef __C430A2D85E1214A2326DC__FOCUSHELP__HPP__
#define __C430A2D85E1214A2326DC__FOCUSHELP__HPP__

#include "vgptr.hpp"
#include "objectdata.hpp"

namespace vwf
{
	class CFocusHelp
	{
	private:
	public:
		bool operator()(CVGPtr<CObjectData> &od){return(od->GetObject()->Enter());};
	};
}

#endif // __C430A2D85E1214A2326DC__FOCUSHELP__HPP__
