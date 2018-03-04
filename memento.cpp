#include<iostream>
#include<string>
#include<vector>

class Memo
{
public:
	std::string state;
	Memo(std::string state)
	{
		this->state = state;
	}
};

class Originator
{
public:
	std::string state;
	void setMemo(Memo *memo)
	{
		this->state = memo->state;
	}

	Memo *createMemo()
	{
		return new Memo(state);
	}

	void show()
	{
		std::cout<<state<<std::endl;
	}
};


class MemoTaker
{
private:
	std::vector<Memo*> memos;

public:
	void saveMemo(Memo *memo)
	{
		memos.push_back(memo);
	}

	Memo *getMemo(int i)
	{
		return memos[i];
	}
};


int main()
{
	Originator *og = new Originator();
	MemoTaker *mt = new MemoTaker;
	
	og->state = "on";
	og->show();
	mt->saveMemo(og->createMemo());

	og->state = "waiting";
	og->show();
	mt->saveMemo(og->createMemo());

	og->state = "off";
	og->show();
	mt->saveMemo(og->createMemo());


	og->setMemo(mt->getMemo(1));
	og->show();

	return 0;
}



