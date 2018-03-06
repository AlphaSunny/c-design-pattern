#include<iostream>
#include<string>
class MobileSoft
{

public:

	virtual void run()=0;
};

class MobileGame: public MobileSoft
{
public:
	void run()
	{
		std::cout<<"play the mobile game"<<std::endl;
	}
};


class MobileApp: public MobileSoft
{
public:
	void run()
	{
		std::cout<<"run the mobile app"<<std::endl;
	}

};


class setMobileUse
{
protected:
	MobileSoft *soft;

public:
	void setMobileUser(MobileSoft *soft)
	{
		this->soft=soft;
	}
	virtual void run()=0;
};

class xuwenMobileUse: public setMobileUse
{
public:
	void run()
	{
		std::cout<<"xuwen is playing the game"<<std::endl;
		soft->run();
	}

};

int main()
{

	setMobileUse *mu;
	mu = new xuwenMobileUse;
	
	MobileGame *soft = new MobileGame;
	mu->setMobileUser(soft);
	mu->run();
	return 0;
}
