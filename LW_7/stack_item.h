#ifndef _STACK_ITEM_H_
#define _STACK_ITEM_H_

#include <iostream>
#include <memory>

template <class T>
class StackItem
{
	T *value;
	StackItem<T> *next;

public:
	StackItem(const T &val, StackItem<T> *node);

	void Set(const T &val);
	T &Get() const;

	void SetNext(StackItem<T> *node);
	StackItem<T> &GetNext() const;

	~StackItem();
};

#endif