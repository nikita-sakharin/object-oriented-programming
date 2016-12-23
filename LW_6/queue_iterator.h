#ifndef _QUEUE_ITERATOR_H_
#define _QUEUE_ITERATOR_H_

#include <iostream>
#include <memory>
#include "queue_item.h"

template <class T>
class QueueIterator
{
	std::shared_ptr<QueueItem<T>> node_ptr;

public:
	QueueIterator(const std::shared_ptr<QueueItem<T>> &node)
	{
		node_ptr = node;
	}

	QueueIterator<T> operator =(const QueueIterator<T> &orig)
	{
		node_ptr = orig.node_ptr;
		return *this;
	}

	std::shared_ptr<QueueItem<T>> operator *()
	{
		return node_ptr;
	}

	std::shared_ptr<QueueItem<T>> operator ->()
	{
		return node_ptr;
	}

	void operator ++()
	{
		if (node_ptr != nullptr)
		{
			node_ptr = node_ptr->GetNext();
		}
	}

	bool operator ==(QueueIterator const &it)
	{
		return node_ptr == it.node_ptr;
	}

	bool operator != (QueueIterator const &it)
	{
		return node_ptr != it.node_ptr;
	}
};

#endif