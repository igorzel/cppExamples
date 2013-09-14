#ifndef CPPTEST_H_
#define CPPTEST_H_

#pragma once

class CPPTest
{
public:
	virtual ~CPPTest(void) {};

	virtual void run(void) = 0;
};

#endif /* CPPTEST_H_ */
