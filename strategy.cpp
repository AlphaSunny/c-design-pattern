#include<iostream>
#include<string>

class CashSuper
{
public:
	virtual double acceptMoney(double i)=0;
};


class CashNormal: public CashSuper
{
public:

	double acceptMoney(double money)
	{
		return money;
	}

};


class CashRebate: public CashSuper
{
private:
	double discount;

public:
	CashRebate(double dis)
	{
		this->discount = dis;
	}

	double acceptMoney(double money)
	{
		return money*discount;
	}
};


class CashReturn: public CashSuper
{
private:
	double threshold;
	double returnMoney;
public:
	CashReturn(double thres, double re)
	{
		this->threshold = thres;
		this->returnMoney = re;
	}

	double acceptMoney(double money)
	{
		if(money<threshold)
		{
			return money;
		}
		else
		{
			return (money - returnMoney);
		}
	}	
};


class CashContext
{
private:
	CashSuper *cs;

public:

	CashContext(std::string str)
	{
		if(str=="normal")
		{
			cs = new CashNormal();
		}
		else if(str=="discount")
		{

                	cs = new CashRebate(0.9);
             	}
		else if(str=="return")
		{
                   	cs = new CashReturn(1000, 20);
                }
		else
		{
			std::cout<<"wrong"<<std::endl;
		}
	}

	double getResult(double money)
	{
		return cs->acceptMoney(money);
	}
};


int main()
{
	double money = 1000;
	CashContext *cc = new CashContext("discount");
	std::cout<< cc->getResult(money);
	return 0;
}




