#pragma once
#include <iostream>

class Referenced
{
public:
	Referenced():m_refCount(0){std::cout<<"Refreenced();"<< std::endl;}
	Referenced(const Referenced&):m_refCount(0){}
	
	// 赋值结果还是自己 
	inline Referenced& operator = (const Referenced&) { return *this; }

	inline int ref() const;
	inline int unref() const;

protected:
	virtual ~Referenced(){std::cout<<"~Refreenced();"<< std::endl;}
private:
	mutable int m_refCount;
};

inline int Referenced::ref() const
{
	return ++m_refCount;
}

inline int Referenced::unref() const
{
	int inewCount = --m_refCount;
	if (inewCount == 0)
	{
		delete this;
	}
	return inewCount;
}

