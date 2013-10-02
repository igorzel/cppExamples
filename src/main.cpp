#include "enable_if.h"
#include "breakOnVariableAccess.h"


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
	//TestRunner<CPPTestEnableIf> testRun1;
	TestRunner<CPPTestBreakOnVariableAccess> testRun2;

	return 0;
}
