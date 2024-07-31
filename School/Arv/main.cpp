#include <iostream>
using namespace std;

#include "Public.h"
#include "Private.h"

void main()
{
	CPublic m_Public;
	CPrivate m_Private;

	m_Private.SetPrivateBaseValue(10);
	m_Private.SetPrivateValue(15);
	m_Private.SetPrivateStaticValue(20);

	m_Public.SetBaseValue(10);
	m_Public.SetPublicValue(15);
	m_Public.SetStaticBaseValue(25);

	cout << "Private Value:\t\t\t" << m_Private.GetPrivateValue() << endl;
	cout << "Private Base Value:\t\t" << m_Private.GetPrivateBaseValue() << endl;
	cout << "Private Static Base Value:\t" << m_Private.GetPrivateStaticValue() << endl << endl;
	cout << "Public Value:\t\t" << m_Public.GetPublicValue() << endl;
	cout << "Public Base Value:\t" << m_Public.GetBaseValue() << endl;
	cout << "Public Static Value:\t" << m_Public.GetStaticBaseValue() << endl;
}