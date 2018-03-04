#include<iostream>
#include<string>
#include<list>
using namespace std;

class Subject;

class Observer
{
protected:
	string name;
	Subject *sub;

public:
	Observer(string name, Subject *sub)
	{
		this->name=name;
		this->sub = sub;
	}

	virtual void update() = 0;
};


class StockObserver : public Observer
{
public:
	StockObserver(string name, Subject *sub) : Observer(name, sub)
	{

	}
	void update();
};


class NBAObserver : public Observer
{
public:
	NBAObserver(string name, Subject *sub) : Observer(name, sub)
	{

	}
	void update();
};


class Subject
{
protected:
	list<Observer*> observers;
public:
	string action;
	virtual void attach(Observer*) = 0;
	virtual void detach(Observer*) = 0;
	virtual void notify() = 0;
};

class Secretary : public Subject
{
	void attach(Observer *observer)
	{
		observers.push_back(observer);
	}

	void detach(Observer *observer)
	{
		list<Observer *>::iterator iter = observers.begin();
		while (iter!=observers.end())
		{
			if ((*iter) == observer)
			{
				observers.erase(iter);
			}
			++iter;
		}
	}

	void notify()
	{
		list<Observer *>::iterator iter = observers.begin();
		while (iter != observers.end())
		{
			(*iter)->update();
			++iter;
		}
	}
};

void StockObserver::update()
{
	cout << name << "�յ���Ϣ" << sub->action << endl;
	if (sub->action == "����������")
	{
		cout << "�����Ϲرչ�Ʊ�����湤��" << endl;
	}
	if (sub->action == "ȥ�Ⱦƣ�")
	{
		cout << "������" << endl;
	}
}


void NBAObserver::update()
{
	cout << name << "�յ���Ϣ" << sub->action << endl;
	if (sub->action == "����������")
	{
		cout << "�����Ϲر�NBA��װ�����湤��������" << endl;
	}
	if (sub->action == "ȥ�Ⱦƣ�")
	{
		cout << "��������" << endl;
	}
}

int main()
{
	Subject *dwq = new Secretary();//��Ϣ���ӣ�����

	Observer *xs = new NBAObserver("xiaoshuai", dwq);//������Ϣ
	Observer *zy = new NBAObserver("zouyue", dwq);
	Observer *lm = new StockObserver("limin", dwq);

	dwq->attach(xs);
	dwq->attach(zy);
	dwq->attach(lm);//���ӵ�����

	dwq->action = "ȥ�Է��ˣ�";
	dwq->notify();
	dwq->action = "ȥ�Ⱦƣ�";
	dwq->notify();
	cout << endl;
	dwq->action = "����������!";
	dwq->notify();
	cin.get();
	return 0;
}