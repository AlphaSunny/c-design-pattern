#include<iostream>
#include<list>

class Person 
{
public:
	const char *action;
	virtual void getConclusion()=0;
};

class Man: public Person
{
public:
	void getConclusion()
	{
		if(action=="success")
		{
			std::cout<<"man is successful"<<std::endl;
		}
		else if(action=="love")
		{
			std::cout<<"man falls in love"<<std::endl;
		}
	}
};


class Woman: public Person
{
public:  
        void getConclusion()  
        {
                if(action=="success")
                {
                	std::cout<<"woman is successful"<<std::endl;
                }
                else if(action=="love")
                {
                        std::cout<<"woman falls in love"<<std::endl;
                }
        }
};

int main()
{
	std::list<Person*> persons;
	
	Person *p1 = new Man();
	p1->action = "success";
	persons.push_back(p1);

	Person *p2 = new Woman();
	p2->action = "love";
	persons.push_back(p2);

	std::list<Person*>::iterator iter = persons.begin();
	while(iter!= persons.end())
	{
		(*iter)->getConclusion();
		++iter;
	} 



}

