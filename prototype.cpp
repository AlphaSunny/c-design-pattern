#include<iostream>
#include<string>


class Resume
{

private:
	std::string name, sex, age, area, company;


public:
	Resume(std::string name)
	{
		this->name = name;
	}

	void setPersonalInfo(std::string s, std::string t)
	{
		this->sex = s;
		this->age = t;
	}

	void setCompany(std::string a, std::string c)
	{
		this->area = a;
		this->company = c;
	}
	
	void display()
	{
		std::cout<<name<<" "<<sex<<" "<<age<<" "<<area<< " "<<company<<std::endl;
	}

	Resume *clone()
	{
		Resume *rs = new Resume(name);
		rs->setPersonalInfo(sex, age);
		rs->setCompany(area, company);
		return rs;
	}

};


int main()
{
	Resume *r = new Resume("wang zhe");
	r->setPersonalInfo("man", "17");
	r->setCompany("shanghai", "zhongjin");
	r->display();

	Resume *rc = r->clone();
	rc->display();
	return 0;
}



