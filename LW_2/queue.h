#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "queue_item.h"

class Queue
{
	QueueItem *head;
	QueueItem *tail;
	size_t count;

public:
	Queue();
	void push_back(Figure * const &);
	Figure *&top();
	void pop();
	bool empty();
	std::size_t size();
	friend std::ostream& operator<<(std::ostream&, const Queue&);
	~Queue();
};

#endif
