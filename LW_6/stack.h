#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <memory>
#include "stack_item.h"

template <class T>
class Stack
{
	StackItem<T> *head;
	std::size_t count;

public:
	Stack();

	void Push(const T &);
	T &Front();
	void Pop();
	bool Empty() const;
	std::size_t Size() const;

	~Stack();
};

#endif