#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include <iostream>
#include <memory>
#include "stack.h"
#include "queue.h"

template <class T>
class Container
{
	Queue<Stack<T>> container;
	std::size_t count;

public:
	Container();

	void Push(T& element);
	void Delete(bool (func)(const T &));
	bool Empty() const;
	std::size_t Size() const;

	template <class A>
	friend std::ostream& operator<<(std::ostream& os, const Container<A>& obj);

	~Container();
};

#endif