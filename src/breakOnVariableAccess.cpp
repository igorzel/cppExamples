#include <iostream>

#include "breakOnVariableAccess.h"

template <class T>
struct DebugThisVariable
{
	T value;

	T& operator()()
	{
		return value;
	}
};


class MyClass
{
public:
	int m_data;

	void callMe(int newVal)
	{
		m_data = newVal;
	}
};

void print(MyClass* my)
{
	std::cout << my->m_data << std::endl;
}

void CPPTestBreakOnVariableAccess::run(void)
{
//////////////////////////////////////////////
// replace:
	//MyClass* obj;
// with:
	DebugThisVariable<MyClass*> obj;
	#define  obj obj()
//////////////////////////////////////////////

	obj = new MyClass;

	if (obj)
	{
		obj->m_data = 123;

		print(obj);

		obj->callMe(456);

		print(obj);

		delete obj;
		obj = nullptr;
	}
}


