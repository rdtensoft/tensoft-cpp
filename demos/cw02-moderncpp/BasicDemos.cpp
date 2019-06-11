//---------------------------------------------------------------------------

#pragma hdrstop

#include "BasicDemos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
// demo_SmartPointers
//  * std::make_unique<Class>
//---------------------------------------------------------------------------

#include <iostream>
#include <memory>

class Bar {
public:
	Bar() { std::cout << "constructed, "; }
	void dosomething() { std::cout << "working, "; }
	~Bar() { std::cout << "destroyed, "; }
};

void demoSmartPointers() {
	std::cout << "  object bar: ";
	{
		Bar* bar = new Bar();
		bar->dosomething();
	}
	std::cout << std::endl;
	std::cout << "  object bar: ";
	{
		auto bar = std::make_unique<Bar>();
		bar->dosomething();
	}
	std::cout << std::endl;
	// -------- -------- -------- --------
}


//---------------------------------------------------------------------------
// demo_MoveConstructor
//  * declare move constructor: Foo(Foo&& foo) { ... }
//---------------------------------------------------------------------------

#include <iostream>
#include <random>
#include <string>
#include <chrono>


#include <ostream>
#include <iomanip>
#include <utility>

class Foo {
public:
	std::string text;
	int value;
	Foo(int n = 0)
		: text{"default"}, value{n}
	{
		std::cout << "  Foo constructor default\n";
	}
	Foo(const Foo& foo)
		: text(foo.text+"."), value{foo.value+1}
	{
		std::cout << "  Foo constructor copy \n";
	}
	Foo(Foo&& foo)
		: text(std::move(foo.text)), value(std::exchange(foo.value, 0))
	{
		std::cout << "  Foo constructor move\n";
    }
    ~Foo() {
		std::cout << "  Foo destructor\n";
    }
};
std::ostream& operator<<(std::ostream &strm, const Foo &foo) {
     return strm << "Foo(text:\"" << foo.text << "\", value:" << foo.value << ")";
}

Foo f(Foo a) {
    return a;
}

void demoMoveConstructor () {
	Foo foo1 = f( Foo(10) );
	std::cout << "    [1] foo1 = " << foo1 << '\n';
	Foo foo2(foo1);
	std::cout << "    [1] foo1 = " << foo1 << '\n';
	std::cout << "    [1] foo2 = " << foo2 << '\n';
	Foo foo3 = std::move(foo1);
	std::cout << "    [1] foo1 = " << foo1 << '\n';
	std::cout << "    [1] foo3 = " << foo3 << '\n';
}

//---------------------------------------------------------------------------
// demo_cpp17_auto
//  * auto in action
//---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <initializer_list>
#include <algorithm>


class Employee {
	// Lots of code here
};

struct PersonID {
	std::string firstName;
	std::string lastName;
};

class Employees {
public:
	auto findEmployee(const std::string Name) { return 1; }
};

int returnAnInt() {
	return 1;
}

auto returnSomething() {
	return 1;
}

// Compiler error, because function could return int and float
auto returnConfusion() {
	std::srand(std::time(0));
	if (std::rand() %2 == 0) {
		// return -1;
		return -1.0;   // to compile change literal to float value: 1.0
	} else {
		return M_PI;
	}
}

std::string intVectorJoin (std::vector<int> v, std::string separator)
{
	auto it = v.begin();
	std::string res = std::to_string(*it);
	for (it = ++it; it != v.end(); ++it)
		res += separator+std::to_string(*it);
	return res;
}



void demoCPP17auto() {
	auto i = returnAnInt();
	auto j = returnSomething();
	auto k = returnConfusion();
	auto al = {10, 11, 12}; // initializer list
	auto employeeList = std::make_unique<Employees>();
	auto person = employeeList->findEmployee("Jane Smith");

	// -----------------------------------------------------
	std::cout << "  i: " << i  << std::endl;
	std::cout << "  j: " << j  << std::endl;
	std::cout << "  k: " << k  << std::endl;
	std::cout << "  list size() = " << al.size() << "  | list: ";
	for (auto elem: al) {
		std::cout << std::to_string(elem) << ' ';
	}
	std::cout << '\n';
	std::vector<int> vi {al};
	std::cout << "  list 1: {" << intVectorJoin(vi,", ") << "}\n";
	std::vector<int> vi2(20);
	std::generate(vi2.begin(), vi2.end(), [](){ return std::rand() % 99; });
	std::cout << "  list 2 : {" << intVectorJoin(vi2,", ") << "}\n";
}

