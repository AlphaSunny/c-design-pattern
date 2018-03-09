#include <iostream>
#include <string>
using namespace std;

//单例模式:
//我有很多一种喜欢的类型的女生，她有很多类型。
//但是在这个类型中存在一个静态类，这个类已经创造出来
//因此我通过这个class创建的对象都是她
//而我再也无法爱上其他人。

//#define  public private 



class Singleton
{
private:
	int i;
	static Singleton *instance;
	Singleton(int i)
	{
		this->i = i;
	}
public:
	static Singleton *getInstance()
	{
		return instance;
	}
	void show()
	{
		cout << i << endl;
	}
};
Singleton* Singleton::instance = new Singleton(8899);

class A :public Singleton
{

};

int mainJ()
{
	Singleton *s = Singleton::getInstance();
	Singleton *s2 = A::getInstance();
	cout << (s == s2) << endl;
	cin.get();
	return 0;
}
