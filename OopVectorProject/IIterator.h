#pragma once
template <class T>
class IIterator
{
public:
	virtual void Set() = 0;
	virtual void Next() = 0;
	virtual bool IsEnd() = 0;
	virtual T& Current() = 0;
};

