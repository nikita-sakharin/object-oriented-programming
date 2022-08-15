#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <memory>
#include "queue_item.h"
#include "queue_iterator.h"

template <class First, class Second, class Third>
class Queue
{
	std::shared_ptr<QueueItem<First, Second, Third>> head;
	std::shared_ptr<QueueItem<First, Second, Third>> tail;
	size_t count;

public:
	Queue();

	void PushBack(std::shared_ptr<First> &&figure_first, std::shared_ptr<Second> &&figure_second, std::shared_ptr<Third> &&figure_third);
	std::shared_ptr<First> TopFirst();
	std::shared_ptr<Second> TopSecond();
	std::shared_ptr<Third> TopThird();
	void Pop();
	bool Empty();
	size_t Size();

	QueueIterator<First, Second, Third> begin();
	QueueIterator<First, Second, Third> end();

	template <class A, class B, class C>
	friend std::ostream& operator<<(std::ostream& os, const Queue<A, B, C>& obj);

	~Queue();
};

#endif