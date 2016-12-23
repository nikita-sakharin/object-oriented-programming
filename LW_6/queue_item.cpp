#include <iostream>
#include <memory>
#include "queue_item.h"

static const std::size_t PULL_SIZE = 8192u;

template <class T> Allocator
QueueItem<T>::allocator(PULL_SIZE, sizeof(QueueItem<T>));

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

	return os;
}

template <class T>
void *QueueItem<T>::operator new(std::size_t size)
{
	++size;//Warning another case
	return allocator.Alloc();
}

template <class T>
void QueueItem<T>::operator delete(void *ptr)
{
	allocator.Free(ptr);
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