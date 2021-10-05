#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base *generate()
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
		std::cout << "It's pointer A\n";
	else if (b)
		std::cout << "It's pointer B\n";
	else if (c)
		std::cout << "It's pointer C\n";
	else
		std::cout << "It's pointer Base\n";
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "It's reference A\n";
		return ;
	}
	catch (...) {}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "It's reference B\n";
		return ;
	}
	catch (...) {}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "It's reference C\n";
		return ;
	}
	catch (...) {}
	std::cout << "It's reference Base\n";
}

int main()
{
	Base *ptr = generate();
	Base &ref = *ptr;

	identify(ptr);
	identify(ref);

	delete ptr;
}
