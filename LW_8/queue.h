#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <memory>

#include <future>
#include <mutex>

#include "queue_item.h"
#include "queue_iterator.h"

template <class T>
class Queue
{
	std::shared_ptr<QueueItem<T>> head;
	std::shared_ptr<QueueItem<T>> tail;
	std::size_t count;

	std::future<void> sort_in_background();
public:
	Queue();

	void Push(std::shared_ptr<T> &&element);
	std::shared_ptr<T> Front();
	void Pop();
	bool Empty() const;
	std::size_t Size() const;

	QueueIterator<T> begin();
	QueueIterator<T> end();

	void sort();
	void sort_parallel();

	template <class A>
	friend std::ostream& operator<<(std::ostream& os, const Queue<A>& obj);

	~Queue();
};

#endif