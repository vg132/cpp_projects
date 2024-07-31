#ifndef __244D269020F11858242D1__PASSIVE__HPP__
#define __244D269020F11858242D1__PASSIVE__HPP__

#include "screenobject.hpp"
#include "vgptr.hpp"

namespace vwf
{
	class CPassive : public CScreenObject
	{
	protected:
		CPassive(void);
	public:
		CVGPtr<CPassive> create();

		bool Enter(){return(false);};
		void Leave(){};

		~CPassive(void);
	};
}

#endif // __244D269020F11858242D1__PASSIVE__HPP__
