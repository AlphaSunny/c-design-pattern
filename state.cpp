#include<iostream>
#include<string>

class Work;
class State;
class ForenonnState;


class State
{
public:
	virtual void writeProgram(Work *) = 0;
};

class Work
{
public:
	int hour;
	State *current;
	Work();

	void writeProgram()
	{
		current->writeProgram(this);
	}
};

class EveningState : public State
{
public:
	void writeProgram(Work *w)
	{
		std::cout << "��ǰʱ��: " << w->hour << "����ܺã��ڿ���������Щ�¶������ջ�ܴ�" << std::endl;
	}
};

class AfternoonState :public State
{
public:
	void writeProgram(Work *w)
	{
		if (w->hour < 19)
		{
			std::cout << "��ǰʱ��: " << w->hour << "������˯�󣬹������Ǿ���ٱ�!" << std::endl;
		}
		else
		{
			w->current = new EveningState();
			w->writeProgram();
		}
	}
};

class ForenonnState :public State
{
public:
	void writeProgram(Work *w)
	{
		if (w->hour < 12)
		{
			std::cout << "��ǰʱ��: " << w->hour << "���繤������ٱ�!" << std::endl;
		}
		else
		{
			w->current = new AfternoonState();
			w->writeProgram();
		}
	}
};

Work::Work()
{
	current = new ForenonnState();
}


int main()
{
	Work *w = new Work();
	w->hour = 21;
	w->writeProgram();
	std::cin.get();
	return 0;
}