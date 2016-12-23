#ifndef _QUEUE_ITEM_H_
#define _QUEUE_ITEM_H_

#include <iostream>
#include <memory>
#include "allocator.h"

template <class T>
class QueueItem
{
	std::shared_ptr<T> element;
	std::shared_ptr<QueueItem<T>> next;
	static Allocator allocator;

public:
	QueueItem(const std::shared_ptr<T> &element);

	void Set(std::shared_ptr<T> &element);
	std::shared_ptr<T> Get() const;

	void SetNext(std::shared_ptr<QueueItem<T>> &node);
	std::shared_ptr<QueueItem<T>> GetNext() const;

	void *operator new (std::size_t size);
	void operator delete(void *ptr);

	template <class A>
	friend std::ostream& operator<<(std::ostream &os, const QueueItem<A> &obj);

	~QueueItem();
};

#endif