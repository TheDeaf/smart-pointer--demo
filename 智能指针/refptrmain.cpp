#include <iostream>
#include "MyObject.h"
#include "ref.h"
#include "Animal.h"

void test()
{

	CMyObject *p1 = new CAnimal;
	p1->m_iNum = 0;
	ref_ptr<CMyObject> ref1 = p1;
	ref1 = new CMyObject();
	system("pause");
	int cc = 0;
}

int main()
{
	test();
	system("pause");
	return 0;
}