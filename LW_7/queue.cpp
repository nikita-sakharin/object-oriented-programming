#include <iostream>
#include <memory>
#include "queue.h"

template <class T>
Queue<T>::Queue()
{
	head = tail = nullptr;
	count = 0u;
}

template <class T>
void Queue<T>::Push(std::shared_ptr<T> &&element)
{
	std::shared_ptr<QueueItem<T>> temp(new QueueItem<T>(element));
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

template <class T>
bool Queue<T>::Empty() const
{
	return !count;
}

template <class T>
size_t Queue<T>::Size() const
{
	return count;
}

template <class T>
std::shared_ptr<T> Queue<T>::Front()
{
	return head->Get();
}

template <class T>
void Queue<T>::Pop()
{
	if (head != nullptr)
	{
		head = head->GetNext();
		if (head == nullptr)
		{
			tail = nullptr;
		}
		--count;
	}
}

template <class T>
QueueIterator<T> Queue<T>::begin()
{
	return QueueIterator<T>(head);
}

template <class T>
QueueIterator<T> Queue<T>::end()
{
	return QueueIterator<T>(nullptr);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& queue)
{
	for (std::shared_ptr<QueueItem<T>> temp = queue.head, local_temp; temp != nullptr; temp = local_temp)
	{
		local_temp = temp->GetNext();
		os << *temp << "\n";
	}

	return os;
}

template <class T>
Queue<T>::~Queue()
{
}

#include "stack.h"
#include "figure.h"
template class
Queue<Stack<Figure *>>;
template
std::ostream& operator<<(std::ostream& os, const Queue<Stack<Figure *>> &obj);