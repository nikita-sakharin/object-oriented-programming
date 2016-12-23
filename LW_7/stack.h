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

	void Push(T &);
	void Pop(bool (*func)(const T &));
	T &Front();
	bool Empty() const;
	std::size_t Size() const;

	template <class A>
	friend std::ostream& operator<<(std::ostream& os, const Stack<A>& obj);

	~Stack();
};

#endif