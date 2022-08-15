#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "queue_item.h"

class Queue
{
	std::shared_ptr<QueueItem> head;
	std::shared_ptr<QueueItem> tail;
	size_t count;

public:
	Queue();

	void push_back(std::shared_ptr<Pentagon> &&figure_pentagon, std::shared_ptr<Hexagon> &&figure_hexagon, std::shared_ptr<Octagon> &&figure_octagon);
	std::shared_ptr<Pentagon> top_pent();
	std::shared_ptr<Hexagon> top_hex();
	std::shared_ptr<Octagon> top_oct();
	void pop();
	bool empty();
	size_t size();

	friend std::ostream& operator<<(std::ostream& os, const Queue& obj);

	~Queue();
};

#endif