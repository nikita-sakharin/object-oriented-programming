#ifndef _QUEUE_ITERATOR_H_
#define _QUEUE_ITERATOR_H_

#include <iostream>
#include <memory>

template <class First, class Second, class Third>
class QueueIterator
{
	std::shared_ptr<QueueItem<First, Second, Third>> node_ptr;

public:
	QueueIterator(std::shared_ptr<QueueItem<First, Second, Third>> node)
	{
		node_ptr = node;
	}

	QueueIterator<First, Second, Third> operator =(const QueueIterator<First, Second, Third>& orig)
	{
		node_ptr = orig.node_ptr;
		return *this;
	}

	std::shared_ptr<QueueItem<First, Second, Third>> operator *()
	{
		return node_ptr;
	}

	std::shared_ptr<QueueItem<First, Second, Third>> operator ->()
	{
		return node_ptr;
	}

	void operator ++()
	{
		node_ptr = node_ptr->GetNext();
	}

	bool operator == (QueueIterator const& i)
	{
		return node_ptr == i.node_ptr;
	}

	bool operator != (QueueIterator const& i)
	{
		return node_ptr != i.node_ptr;
	}
};

#endif