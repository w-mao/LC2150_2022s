/*
 * QueueEmpty.h
 *
 *  Created on: Feb 24, 2022
 *      Author: mao
 */

#ifndef HEAPS_AND_PRIORITY_QUEUES_QUEUEEMPTY_H_
#define HEAPS_AND_PRIORITY_QUEUES_QUEUEEMPTY_H_

#include <iostream>
#include "RuntimeException.h"
using namespace std;


class QueueEmpty : public RuntimeException {
public:
	QueueEmpty(const string& err) : RuntimeException(err) { }
};


#endif /* HEAPS_AND_PRIORITY_QUEUES_QUEUEEMPTY_H_ */
