#include<iostream>
#include<string>

class Country;
class UniteNations
{
public:
	virtual void declare(std::string message, Country *colleague) = 0;
};

class Country
{
protected:
	UniteNations * mediator;
public:
	Country(UniteNations *mediator)
	{
		this->mediator = mediator;
	}
};

class USA :public Country
{
public:
	USA(UniteNations *mediator) :Country(mediator)
	{
	}
	void declare(std::string message)
	{
		std::cout << "美发布信息: " << message << std::endl;
		mediator->declare(message, this);
	}
	void getMessage(std::string message)
	{
		std::cout << "美国获得对方信息: " << message << std::endl;
	}
};

class Iraq :public Country
{
public:
	Iraq(UniteNations *mediator) :Country(mediator)
	{
	}
	void declare(std::string message)
	{
		std::cout << "伊拉克发布信息: " << message << std::endl;
		mediator->declare(message, this);
	}
	void getMessage(std::string message)
	{
		std::cout << "伊拉克获得对方信息: " << message << std::endl;
	}
};

class UnitedNationsSecurityCouncil :public UniteNations
{
public:
	USA * usa;
	Iraq *iraq;
	void declare(std::string message, Country *colleague)
	{
		if (colleague == usa)
		{
			iraq->getMessage(message);
		}
		else
		{
			usa->getMessage(message);
		}
	}
};

int main()
{
	UnitedNationsSecurityCouncil *unsc = new UnitedNationsSecurityCouncil();

	USA *c1 = new USA(unsc);
	Iraq *c2 = new Iraq(unsc);

	unsc->usa = c1;
	unsc->iraq = c2;

	c1->declare("不准开发核武器，否则打你！");
	c2->declare("他妈的美国去死！");

	std::cin.get();
	return 0;
}