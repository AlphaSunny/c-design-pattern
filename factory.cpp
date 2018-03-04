#include<iostream>
#include<string>

class Operator
{
public:
	double a;
	double b;
	virtual double getResult()=0;
};


class addOper: public Operator
{
public:
	double getResult()
	{
		return a+b; 
	}
};


class subOper: public Operator
{
	double getResult()
	{
		return a-b;
	}
};


class mulOper: public Operator
{
public:
	double getResult()
	{
		return a*b;
	}
};


class divOper: public Operator
{
public:
	double getResult()
	{
		return a/b;
	}
};

class IFactory
{
public:
	virtual Operator *createOperation()=0;
};


class addFactory: public IFactory
{
public:
	static Operator *createOperator()
	{
		return new addOper();
	}
};


class subFactory: public IFactory
{
public:
	static Operator *createOperator()
	{
		return new subOper();
	}
};

class mulFactory: public IFactory
{
public:
	static Operator *createOperator()
	{
		return new mulOper();
	}
};

class divFactory: public IFactory
{
public:
	static Operator *createOperator()
	{
		return new divOper();
	}
};


int main()
{
	Operator *oper = mulFactory::createOperator();
	oper->a = 3;
	oper->b = 4;
	std::cout<< oper->getResult()<<std::endl;

}
