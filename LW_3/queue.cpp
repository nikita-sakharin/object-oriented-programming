#include "queue.h"

Queue::Queue()
{
	head = tail = nullptr;
	count = 0u;
}

void Queue::push_back(std::shared_ptr<Pentagon> &&figure_pentagon, std::shared_ptr<Hexagon> &&figure_hexagon, std::shared_ptr<Octagon> &&figure_octagon)
{
	std::shared_ptr<QueueItem> temp(new QueueItem(figure_pentagon, figure_hexagon, figure_octagon, nullptr));
	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		tail->SetNext(temp);
	}
	tail = temp;
	++count;
}

bool Queue::empty()
{
	return !count;
}

size_t Queue::size()
{
	return count;
}

std::shared_ptr<Pentagon> Queue::top_pent()
{
	return head->GetPentagon();
}

std::shared_ptr<Hexagon> Queue::top_hex()
{
	return head->GetHexagon();
}

std::shared_ptr<Octagon> Queue::top_oct()
{
	return head->GetOctagon();
}

void Queue::pop()
{
	if (head != nullptr)
	{
		head = head->GetNext();
		--count;
	}
}


std::ostream& operator<<(std::ostream& os, const Queue& queue)
{
	for (std::shared_ptr<QueueItem> temp = queue.head, local_temp; temp != nullptr; temp = local_temp)
	{
		local_temp = temp->GetNext();
		os << "[\n" << *temp << "]\n";
	}

	return os;
}

Queue::~Queue()
{
}