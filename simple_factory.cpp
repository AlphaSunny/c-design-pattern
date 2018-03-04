#include<iostream>

class Operator
{
public:
	double a;
	double b;
	virtual double getResult()=0;
};

class addOper:public Operator
{
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
	double getResult()
	{
		return a*b;
	}

};


class divOper: public Operator
{
	double getResult()
	{
		return a/b;

	}
};


class Factory
{
public:

	static Operator *createOperator(char c)
	{
		switch(c)
		{
			case '+':
				return new addOper();
				break;
		
			case '-': 
                        	return new subOper();
                        	break;

			case '*': 
                        	return new mulOper();
                        	break;
	
			case '/': 
                        	return new divOper();
                        	break;
		}
	}

};

int main()
{
	Operator *oper = Factory::createOperator('+');
	oper->a = 3;
	oper->b = 4;
	std::cout<< oper->getResult()<<std::endl;

	return 0;
}
