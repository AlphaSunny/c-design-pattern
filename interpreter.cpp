#include<iostream>
#include<list>


class Context;

class AbstractInterpreter
{
public:
	virtual void interpret(Context *)=0;
};

class TerminalInterpreter: public AbstractInterpreter
{
public:
	void interpret(Context *context)
	{
		std::cout<<"terminal interpreter"<<std::endl;
	}

};

class NonTerminalInterpreter: public AbstractInterpreter
{
public:
	void interpret(Context *context)
	{
		std::cout<<"NonTerminal interpreter"<<std::endl;
	}

};

class Context
{
public:
	int i;
};

int main()
{
	Context *context;
	std::list<AbstractInterpreter*> inter;
	inter.push_back(new TerminalInterpreter());
	inter.push_back(new NonTerminalInterpreter());
	inter.push_back(new TerminalInterpreter());
	inter.push_back(new TerminalInterpreter());

	for(std::list<AbstractInterpreter*>::iterator iter=inter.begin(); iter!= inter.end(); iter++)
	{
		(*iter)->interpret(context);
	}

	return 0;
}
