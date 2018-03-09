#include<iostream>
#include<string>

//适配器模式
//男人是一个类
//可以生产出各种各样的男人
//有一个类叫女人
//男人要fuck，但是男人和女人的属性是不同的
//这时候，我们就需要一个适配器，这个适配器以男人的方式创建
//但是这个适配器里面包含一个女人的类，这时候就可以通过男人初始化的方式实现对女人的赋值。
class Player
{
public:
	std::string name;
	Player(std::string name)
	{
		this->name = name;
	}

	virtual void attack()=0;
	virtual void defeat() = 0;
};

class Forward: public Player
{
public: 
	Forward(std::string name): Player(name)
	{

	}
	void attack()
	{
		std::cout<<"forward is attacking"<<std::endl;
	}

	void defeat()
	{
		std::cout<<"forward is defeating"<<std::endl;
	}
};

class Center: public Player
{
public: 
	Center(std::string name): Player(name)
        {

        }
	
        void attack()
        {
                std::cout<<"center is attacking"<<std::endl;
        }

        void defeat()
        {
                std::cout<<"center is defeating"<<std::endl;
        }
};

class Guard: public Player
{
public: 
	Guard(std::string name): Player(name)
        {

        }

        void attack()
        {
                std::cout<<"guard is attacking"<<std::endl;
        }

        void defeat()
        {
                std::cout<<"guard is defeating"<<std::endl;
        }
};



class ForeignPlayer
{
public:
	std::string name;
	ForeignPlayer(std::string name)
	{
		this->name = name;
	}	

	void attack()
	{
		std::cout<<name<<"Foreign Player is attacking"<<std::endl;
	}

	void defeat()
	{
		std::cout<<name<<"Foreign player is defeating"<<std::endl;
	}

}; 




class Translater: public Player 
{ 
private:
        ForeignPlayer *fp;
public: 
        Translater(std::string name):Player(name)
        {
                fp = new ForeignPlayer(name);
        }       

        void attack()
        {
                fp->attack();
        }

        void defeat()
        {
                fp->defeat();
        }

}; 



int main()
{
	Player *p1 = new Forward("wangzhe");
	p1->attack();
	p1->defeat();

	Translater *yao = new Translater("yaoming");
	yao->attack();
	yao->defeat();

	return 0;
}
