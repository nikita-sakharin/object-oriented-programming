#ifndef _QUEUE_ITEM_H_
#define _QUEUE_ITEM_H_

#include <iostream>
#include <memory>

template <class T>
class QueueItem
{
	std::shared_ptr<T> element;
	std::shared_ptr<QueueItem<T>> next;

public:
	QueueItem(const std::shared_ptr<T> &element);

	void Set(std::shared_ptr<T> &element);
	std::shared_ptr<T> Get() const;

	void SetNext(std::shared_ptr<QueueItem<T>> &node);
	std::shared_ptr<QueueItem<T>> GetNext() const;

	template <class A>
	friend std::ostream& operator<<(std::ostream &os, const QueueItem<A> &obj);

	~QueueItem();
};

#endif