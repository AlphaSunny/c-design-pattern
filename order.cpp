#include<iostream>
#include<string>
#include<list>

class Barbecuer
{
public:
	void makeMutton()
	{
		std::cout<<"the barbecuer is making mutton"<<std::endl;
	}

	void makeWing()
	{
		std::cout<<"the barbecure is making wing"<<std::endl;
	}
};

class Command
{
protected:
	Barbecuer *barbecuer;
public:
	Command(Barbecuer *bar)
	{
		this->barbecuer = bar;
	}
	virtual void executeCommand()=0;	
};


class MakeMuttonCommand:public  Command
{
public:
	MakeMuttonCommand(Barbecuer *bar): Command(bar)
	{
	}
	void executeCommand()
	{
		barbecuer->makeMutton();
	}
};

class MakeWingCommand: public Command
{
public:
	MakeWingCommand(Barbecuer *bar): Command(bar)
	{
	}
	void executeCommand()
	{
		barbecuer->makeWing();
	}
};


class Waiter
{
private:
	Command *command;
public:
	void setOrder(Command *command)
	{
		this->command= command;
	}
	void notify()
	{
		command->executeCommand();
	}

};

class Manager
{
private:
	std::list<Command*> orders;

public:
	void setOrder(Command *command)
	{
		orders.push_back(command);
	}

	void notify()
	{
		std::list<Command*>::iterator iter= orders.begin();
		while(iter!= orders.end())
		{
			(*iter)->executeCommand();
			++iter;
		}
	}
};

int main()
{
	Barbecuer *bar;
	Command *com = new MakeMuttonCommand(bar);
	Waiter *wai = new Waiter;
	wai->setOrder(com);
	wai->notify();
	return 0;
}

