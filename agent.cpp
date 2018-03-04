#include<iostream>

class SchoolGirl
{
public:
	std::string name;

};

class IGiveGift
{
public:
	virtual void giveDolls()=0;
	virtual void giveFlowers()=0;
};

class Pursuit: public IGiveGift
{
private:
	SchoolGirl mm;

public:
// you must have the void constructor in the g++, not in vc
	Pursuit()
	{

	}
	Pursuit(SchoolGirl m)
	{
		this->mm = m;
	}

	void giveDolls()
	{
		std::cout<<mm.name<< ", give you dolls"<<std::endl;
	}

	void giveFlowers()
	{
		std::cout<<mm.name<<", give you flowers"<<std::endl;
	}
};

class Proxy: public Pursuit
{
private:
	Pursuit gg;

public:

	Proxy(SchoolGirl mm): gg(mm)
	{
	
	}

	void giveDolls()
	{
		gg.giveDolls();
	}

	void giveFlowers()
	{
		gg.giveFlowers();
	}

};


int main()
{
	SchoolGirl wangzhe;
	wangzhe.name = "wang zhe";
	Proxy xuwen(wangzhe);
	xuwen.giveDolls();	

}

