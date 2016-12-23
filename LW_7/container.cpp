#include <iostream>
#include <memory>

#include "container.h"

const static std::size_t BOUND = 5u;

template <class T>
Container<T>::Container() : container(), count(0)
{
}

template <class T>
void Container<T>::Push(T& element)
{
	if (container.Empty() || container.Front()->Size() > BOUND)
	{
		container.Push(std::shared_ptr<Stack<T>>(new Stack<T>));
	}
	container.Front()->Push(element);

	++count;
}

template <class T>
void Container<T>::Delete(bool (func)(const T &))
{
	count = 0u;
	for (auto x = container.begin(); x != container.end(); ++x)
	{
		x->Get()->Pop(func);
		count += x->Get()->Size();
	}
}

template <class T>
bool Container<T>::Empty() const
{
	return !count;
}

template <class T>
size_t Container<T>::Size() const
{
	return count;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Container<T>& contain)
{
	os << contain.container;
	return os;
}

template <class T>
Container<T>::~Container()
{
}

#include "figure.h"
template class
Container<Figure *>;
template
std::ostream& operator<<(std::ostream& os, const Container<Figure *> &obj);