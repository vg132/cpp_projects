#ifndef __201C398AE28EA6B537E39__APP__HPP__
#define __201C398AE28EA6B537E39__APP__HPP__

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "vwf.hpp"

class CApp
{
private:
	Event event;
	vwf::CVGPtr<vwf::CButton> m_Button;
	vwf::CVGPtr<vwf::CAction<CApp> > m_Action;
	vwf::CVGPtr<vwf::CAction<CApp> > m_EditAction;
public:
	void Start();
	void Action(Event event, vwf::CVGPtr<vwf::CScreenObject> scrObj);
	void EditAction(Event event, vwf::CVGPtr<vwf::CScreenObject> scrObj);

	CApp(void);
	~CApp(void);
};

#endif // __201C398AE28EA6B537E39__APP__HPP__
