#include <iostream>
#include <cstdlib>

class Base {
public:
	virtual ~Base() {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *generate(void)
{
	int rand_num;

	srand(time(NULL));
	rand_num = rand() % 4;
	switch (rand_num)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return new Base;
	}
}

void identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);

	if (a)
		std::cout << "It's A\n";
	else if (b)
		std::cout << "It's B\n";
	else if (c)
		std::cout << "It's C\n";
	else
		std::cout << "It's Base\n";
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "It's A\n";
		return ;
	}
	catch (...) {}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "It's B\n";
		return ;
	}
	catch (...) {}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "It's C\n";
		return ;
	}
	catch (...) {}
	std::cout << "It's Base\n";
}

int main()
{
	Base *p = generate();

	identify(p);

	delete p;
}
