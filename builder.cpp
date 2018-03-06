#include<iostream>
#include<vector>

class Person
{
public:
	virtual void createHead()=0;
	virtual void createHand()=0;
	virtual void createFoot()=0;
	virtual void createLeg() = 0;

};


class ThinPerson: public Person
{
public:
	void createHead()
	{
		std::cout<< "create thin head" <<std::endl;
	}

	void createHand() 
        {
                std::cout<< "create thin hand" <<std::endl;
        }


	void createFoot() 
        {
                std::cout<< "create thin foot" <<std::endl;
        }

	void createLeg() 
        {
                std::cout<< "create thin leg" <<std::endl;
        }
};



class FatPerson: public Person
{
public:
        void createHead() 
        {
                std::cout<< "create fat head" <<std::endl;
        }

        void createHand() 
        {
                std::cout<< "create fat hand" <<std::endl;
        }


        void createFoot() 
        {
                std::cout<< "create fat foot" <<std::endl;
        }

        void createLeg() 
        {
                std::cout<< "create fat leg" <<std::endl;
        }
};


class Builder
{
private:
	Person *p;

public:
	Builder(Person *p)
	{
		this->p = p;
	}

	void build()
	{
		p->createHead();
		p->createHand();
		p->createFoot();
		p->createLeg();
	}
};


int main()
{
	FatPerson *fp = new FatPerson;

	Builder *builder = new Builder(fp); 
	builder->build();

	delete fp;
	delete builder;

	return 0;


}



