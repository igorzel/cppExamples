#include "enable_if.h"


template<class T>
class TestRunner
{
public:
	TestRunner()
	{
		T* test = new T();
		test->run();
		delete test;
	}
};

int main()
{
	TestRunner<CPPTestEnableIf> testRun1;

	return 0;
}
