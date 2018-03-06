#include<iostream>
#include<list>
#include<map>
#include<string>


class Website
{
public:
	virtual void use()=0;
};

class ConcreteWebsite: public Website
{
private:
	std::string name;

public:
	ConcreteWebsite(std::string name)
	{
		this->name = name;
	}
	void use()
	{
		std::cout<<"use the website "<< name<<std::endl;
	}
};

class WebsiteFactory
{
private:
	std::map<std::string, Website *> wf;

public:
	Website *getWebsite(std::string key)
	{
		if(wf.find(key) == wf.end())
		{
			wf[key] = new ConcreteWebsite(key);
		}
		return wf[key];
	}

	int count()
	{
		return wf.size();
	}
};

int main()
{
	
	WebsiteFactory *wf = new WebsiteFactory();

	Website *w1 = wf->getWebsite("google");
	w1->use();

	Website *w2 = wf->getWebsite("baidu");
	w2->use();

	std::cout<< wf->count()<<std::endl;

	return 0;
}






