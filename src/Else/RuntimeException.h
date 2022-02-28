/*
 * RuntimeException.h
 *
 *  Created on: Feb 24, 2022
 *      Author: mao
 */

#ifndef HEAPS_AND_PRIORITY_QUEUES_RUNTIMEEXCEPTION_H_
#define HEAPS_AND_PRIORITY_QUEUES_RUNTIMEEXCEPTION_H_

#include <iostream>
using namespace std;

class RuntimeException { // generic run-time exception
private:
	string errorMsg;
public:
	RuntimeException(const string& err) { errorMsg = err; }
	string getMessage() const { return errorMsg; }
};



#endif /* HEAPS_AND_PRIORITY_QUEUES_RUNTIMEEXCEPTION_H_ */
