#include<iostream>

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
