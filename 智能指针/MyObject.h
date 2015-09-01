#pragma once
#include "referenced.h"
class CMyObject : public Referenced
{
public:
	CMyObject(void);
protected:
	virtual ~CMyObject(void);

public:
	int m_iNum;
};

