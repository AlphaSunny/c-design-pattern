#include<iostream>

class Iterator;

class Aggregate
{
	virtual Iterator *createIterator()=0;

};


class Iterator
{
	virtual void first();
	virtual void next();
	virtual bool isDone();
	virtual bool isDoneA();
};

class ConcreteAggregate: public Iterator
{
	void first()
	{

	}
	void next()
	{
	}
	bool isDone()
	{
	}
	virtual bool isDoneA()
	{
	}



};


int main()
{
	return 0;
}
