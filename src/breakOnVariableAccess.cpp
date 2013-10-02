#include <iostream>

#include "breakOnVariableAccess.h"

template<class T>
T& breakOnVariableAccess(T& variable)
{
	return variable;
}


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
	MyClass* obj_DEBUG;
	#define  obj breakOnVariableAccess(obj_DEBUG)
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


