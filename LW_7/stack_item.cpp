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
std::ostream& operator<<(std::ostream& os, const StackItem<T> &obj)
{
//	os << *obj.value << "\n";
	(*obj.value)->Print(os);
	os << "\n";

	return os;
}

template <class T>
StackItem<T>::~StackItem()
{
	delete value;
}

#include "figure.h"
template class
StackItem<Figure *>;
template
std::ostream& operator<<(std::ostream& os, const StackItem<Figure *> &obj);
/*
template class
StackItem<int>;
template
std::ostream& operator<<(std::ostream& os, const StackItem<int> &obj);
*/