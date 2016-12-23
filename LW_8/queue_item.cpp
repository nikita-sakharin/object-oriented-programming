#include <iostream>
#include <memory>
#include "queue_item.h"

template <class T>
QueueItem<T>::QueueItem(const std::shared_ptr<T> &elem)
{
	element = elem;
	next = nullptr;
}

template <class T>
void QueueItem<T>::Set(std::shared_ptr<T> &elem)
{
	element = elem;
}

template <class T>
std::shared_ptr<T> QueueItem<T>::Get() const
{
	return element;
}

template <class T>
void QueueItem<T>::SetNext(std::shared_ptr<QueueItem<T>> &node)
{
	next = node;
}

template <class T>
std::shared_ptr<QueueItem<T>> QueueItem<T>::GetNext() const
{
	return next;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const QueueItem<T> &obj)
{
	obj.element->Print(os);
	os << "\n";
/*
	os << *obj.Get() << "\n";
*/
	return os;
}

template <class T>
QueueItem<T>::~QueueItem()
{
}

#include "figure.h"
template class
QueueItem<Figure>;
template
std::ostream& operator<<(std::ostream& os, const QueueItem<Figure> &obj);
/*
template class
QueueItem<int>;
template
std::ostream& operator<<(std::ostream& os, const QueueItem<int> &obj);
*/