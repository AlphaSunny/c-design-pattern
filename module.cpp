#include<iostream>
#include<string>

class people
{
public:
	void show()
	{
		std::cout<<"he is coming"<<getName()<<std::endl;
	}

protected:
	virtual std::string getName()=0;
};

class xuwen: public people
{
protected:
	std::string getName()
	{
		std::cout<<"xuwen is so cute"<<std::endl;
	}
};

class yangguang: public people
{
protected:
	std::string getName()
	{
		std::cout<<"yangguang beat"<<std::endl;
	}
};


int main()
{
	xuwen *xu = new xuwen();
	yangguang *yang = new yangguang();
	xu->show();
	return 0;
}
