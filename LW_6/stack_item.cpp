#include <iostream>
#include <memory>
#include "stack_item.h"

template <class T>
StackItem<T>::StackItem(const T &val, StackItem<T> *node)
{
	value = new T(val);
	next = node;
}

template <class T>
void StackItem<T>::Set(const T &val)
{
	*value = val;
}

template <class T>
T &StackItem<T>::Get() const
{
	return *value;
}

template <class T>
void StackItem<T>::SetNext(StackItem<T> *node)
{
	next = node;
}

template <class T>
StackItem<T> &StackItem<T>::GetNext() const
{
	return *next;
}

template <class T>
StackItem<T>::~StackItem()
{
	delete value;
}

typedef unsigned char Byte;

template class
StackItem<void *>;