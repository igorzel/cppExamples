#include <iostream>
#include <type_traits>

#include "enable_if.h"

class Base
{
public:
	virtual ~Base() {};

	virtual std::string getName(void) = 0;
};

class A : public Base
{
public:
	virtual std::string getName(void) override
	{
		return "A";
	}
};

class B : public Base
{
public:
	virtual std::string getName(void) override
	{
		return "B";
	}
};

class C
{
public:
	virtual ~C() {};

	virtual std::string getName(void)
	{
		return "C";
	}
};


template<class T>
struct ParamHolder
{
	ParamHolder(T v) : val(v) {};
	T val;
};

template<class T>
void globalFunction
		(ParamHolder<T> &obj,
		 typename std::enable_if<std::is_base_of<Base, T>::value>::type* = 0)
{
    std::cout << R"(Hello from class that is derived from "Base": )" << obj.val.getName();
	std::cout << std::endl;
}

template<class T>
void globalFunction
		(ParamHolder<T> &obj,
		 typename std::enable_if<!std::is_base_of<Base, T>::value>::type* = 0)
{
    std::cout << R"(Hello from class that is NOT derived from "Base": )" << obj.val.getName();
	std::cout << std::endl;
}


void CPPTestEnableIf::run(void)
{
	A a;
	ParamHolder<A> ah(a);
	globalFunction<A>(ah);

	B b;
	ParamHolder<B> bh(b);
	globalFunction<B>(bh);

	C c;
	ParamHolder<C> ch(c);
	globalFunction<C>(ch);
}

// Output:
//
// Hello from class that is derived from "Base": A
// Hello from class that is derived from "Base": B
// Hello from class that is NOT derived from "Base": C
//
