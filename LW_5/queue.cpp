#include <iostream>
#include <memory>
#include "queue.h"

template <class First, class Second, class Third>
Queue<First, Second, Third>::Queue()
{
	head = tail = nullptr;
	count = 0u;
}

template <class First, class Second, class Third>
void Queue<First, Second, Third>::PushBack(std::shared_ptr<First> &&figure_first, std::shared_ptr<Second> &&figure_second, std::shared_ptr<Third> &&figure_third)
{
	std::shared_ptr<QueueItem<First, Second, Third>> temp(new QueueItem<First, Second, Third>(figure_first, figure_second, figure_third));
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

template <class First, class Second, class Third>
bool Queue<First, Second, Third>::Empty()
{
	return !count;
}

template <class First, class Second, class Third>
size_t Queue<First, Second, Third>::Size()
{
	return count;
}

template <class First, class Second, class Third>
std::shared_ptr<First> Queue<First, Second, Third>::TopFirst()
{
	return head->GetFirst();
}

template <class First, class Second, class Third>
std::shared_ptr<Second> Queue<First, Second, Third>::TopSecond()
{
	return head->GetSecond();
}

template <class First, class Second, class Third>
std::shared_ptr<Third> Queue<First, Second, Third>::TopThird()
{
	return head->GetThird();
}

template <class First, class Second, class Third>
void Queue<First, Second, Third>::Pop()
{
	if (head != nullptr)
	{
		head = head->GetNext();
	}

	if (head == nullptr)
	{
		tail = nullptr;
	}

	--count;
}

template <class First, class Second, class Third>
QueueIterator<First, Second, Third> Queue<First, Second, Third>::begin()
{
	return QueueIterator<First, Second, Third>(head);
}

template <class First, class Second, class Third>
QueueIterator<First, Second, Third> Queue<First, Second, Third>::end()
{
	return QueueIterator<First, Second, Third>(nullptr);
}

template <class First, class Second, class Third>
std::ostream& operator<<(std::ostream& os, const Queue<First, Second, Third>& queue)
{
	for (std::shared_ptr<QueueItem<First, Second, Third>> temp = queue.head, local_temp; temp != nullptr; temp = local_temp)
	{
		local_temp = temp->GetNext();
		os << "[\n" << *temp << "]\n";
	}

	return os;
}

template <class First, class Second, class Third>
Queue<First, Second, Third>::~Queue()
{
}

#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"

template class
Queue<Pentagon, Hexagon, Octagon>;
template
std::ostream& operator<<(std::ostream& os, const Queue<Pentagon, Hexagon, Octagon>& obj);