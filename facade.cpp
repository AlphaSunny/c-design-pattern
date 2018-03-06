#include<iostream>

class sub1
{
public:
	void run()
	{
		std::cout<<"sub1 is created"<<std::endl;
	}
};

class sub2
{
public:
	void run()
	{
		std::cout<<"sub2 is created"<<std::endl;
	}
};


class sub3
{
public:
	void run()
	{
		std::cout<<"sub3 is created"<<std::endl;
	}
};


class Facade
{
private:
	sub1 *s1;
	sub2 *s2;
	sub3 *s3;
public:
	Facade()
	{
		s1 = new sub1;
		s2 = new sub2;
		s3 = new sub3;
	}

	void run()
	{
		s1->run();
		s2->run();
		s3->run();
	}
	
};


int main()
{
	Facade *fa = new Facade();
	fa->run();
	return 0;
}
