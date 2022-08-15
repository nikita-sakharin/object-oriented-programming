#include "queue.h"

Queue::Queue() : head(nullptr), tail(nullptr), count(0u)
{
}

Queue::~Queue()
{
	for (QueueItem *temp = head, *local_temp; temp != nullptr; temp = local_temp)
	{
		local_temp = temp->next;
		delete temp;
	}
}

void Queue::push_back(Figure * const &value)
{
	QueueItem *temp = new QueueItem(value);

	if (head == nullptr)
	{
		head = temp;
	}
	else
	{
		tail->next = temp;
	}
	tail = temp;
	count++;
}

void Queue::pop()
{
	if (head != nullptr)
	{
		QueueItem *temp = head;
		head = temp->next;
		if (temp->next == nullptr)
		{
			tail = nullptr;
		}
		delete temp;
		--count;
	}
}

bool Queue::empty()
{
	return count == 0u;
}

std::size_t Queue::size()
{
	return count;
}

Figure *&Queue::top()
{
	return head->data;
}

std::ostream& operator<<(std::ostream& os, const Queue& obj)
{
	for (QueueItem *temp = obj.head; temp != nullptr; temp = temp->next)
	{
		temp->data->Print();
	}

	return os;
}
