#include<iostream>


//抽象工厂模式：
//女人是一个抽象类，她可以是有钱型，也可以是穷人型
//男人也是一个抽象类，他可以是有钱型，也可以是穷人型

//有一个婚姻机构可以进行牵线
//这时候有穷人的婚姻机构，这里只生产穷的男人和穷的女人一起生产。
//只是后有富人的婚姻机构，这里只生产有钱的男人和有钱的女人

class IUser
{
public:
	virtual void getUser() = 0;
	virtual void setUser() = 0;
};

class SqlUser: public IUser
{
public:
	void getUser()
	{
		std::cout<< "get User from the sql" <<std::endl;
	}

	void setUser()
	{
		std::cout<< "set User in the sql"<< std::endl;
	}
};


class AccessUser:public IUser
{
public:
	void getUser()
	{
		std::cout<<"get user from the access"<<std::endl;
	}
	void setUser()
	{
		std::cout<<"set user from the access"<<std::endl;
	}
};

class IDepartment
{
public:
	virtual void getDepartment() =0;
	virtual void setDepartment() =0;
};

class SqlDepartment: public IDepartment
{
public:
	void getDepartment()
	{
		std::cout<<"get sql department"<<std::endl;
	}

	void setDepartment()
	{
		std::cout<<"set sql department"<<std::endl;
	}
};

class AccessDepartment: public IDepartment
{
public: 
        void getDepartment() 
        {
                std::cout<<"get access department"<<std::endl;
        }

        void setDepartment()
        {
                std::cout<<"set access department"<<std::endl;
        }
};

class IFactory
{
public:
	virtual IUser *createUser()=0;
	virtual IDepartment *createDepartment()=0;
};

class SqlFactory: public IFactory
{
public:
	IUser *createUser()
	{
		return new SqlUser();
	}
	
	IDepartment *createDepartment()
	{
		return new SqlDepartment();
	}

};

class AccessFactory:public IFactory
{
public:
	IUser *createUser()
	{
		return new AccessUser();
	}
	
	IDepartment *createDepartment()
	{
		return new AccessDepartment();
	}
};


int main()
{

	IFactory *fact = new SqlFactory();
	IUser *user = fact->createUser();
	IDepartment *department = fact->createDepartment();

	user->setUser();
	department->getDepartment();
	return 0;
}
