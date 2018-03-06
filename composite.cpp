#include<iostream>
#include<vector>
#include<string>


class Component
{
public:
	std::string name;
	Component(std::string name)
	{
		this->name = name;
	}
	virtual void add(Component *) = 0;
	virtual void remove(Component *) = 0;
	virtual void display(int) = 0;
};

class Leaf : public Component
{

public:
	Leaf(std::string name) :Component(name)
	{

	}

	void add(Component *c)
	{
		std::cout << "lead cannot add" << std::endl;
	}

	void remove(Component *c)
	{
		std::cout << "leaf cannot remove" << std::endl;
	}

	void display(int depth)
	{
		std::string str(depth, '-');
		str += name;
		std::cout << str << std::endl;
	}
};

class Composite : public Component
{
private:
	std::vector<Component*> component;

public:
	Composite(std::string name) :Component(name)
	{}
	void add(Component *c)
	{
		component.push_back(c);
	}

	void remove(Component *c)
	{
		std::vector<Component*>::iterator iter = component.begin();
		while (iter != component.end())
		{
			if (*iter == c)
			{
				component.erase(iter);
			}
			iter++;
		}
	}

	void display(int depth)
	{
		std::string str(depth, '-');
		str += name;
		std::cout << str << std::endl;

		std::vector<Component*>::iterator iter = component.begin();
		while (iter != component.end())
		{
			(*iter)->display(depth + 2);
			iter++;
		}
	}
};

int main()
{
	Component *p = new Composite("小李");
	p->add(new Leaf("小王"));
	p->add(new Leaf("小强"));

	Component *sub = new Composite("小虎");
	sub->add(new Leaf("小王"));
	sub->add(new Leaf("小明"));
	sub->add(new Leaf("小柳"));

	p->add(sub);
	p->display(0);

	std::cout << "*******" << std::endl;
	sub->display(2);

	std::cin.get();

	return 0;
}