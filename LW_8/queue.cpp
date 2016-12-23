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

template<class T>
std::future<void> Queue<T>::sort_in_background()
{
	std::packaged_task<void(void)> task(std::bind(std::mem_fn(&Queue<T>::sort_parallel), this));
	std::future<void> res(task.get_future());
	std::thread th(std::move(task));
	th.detach();

	return res;
}

template <class T>
void Queue<T>::sort_parallel()
{
	if (this->Size() < 2u)
	{
		return;
	}

	std::shared_ptr<T> pattern = head->Get();
	this->Pop();

	Queue<T> less, great;
	while (!this->Empty())
	{
		if (*head->Get() > *pattern)
		{
			less.Push(head->Get());
		}
		else
		{
			great.Push(head->Get());
		}
		this->Pop();
	}


	std::future<void> less_result = less.sort_in_background();
	std::future<void> great_result = great.sort_in_background();

	less_result.get();
	while (!less.Empty())
	{
		this->Push(less.Front());
		less.Pop();
	}

	this->Push(std::shared_ptr<T>(pattern));

	great_result.get();
	while (!great.Empty())
	{
		this->Push(great.Front());
		great.Pop();
	}
}

template <class T>
void Queue<T>::sort()
{
	if (this->Size() < 2u)
	{
		return;
	}

	std::shared_ptr<T> pattern = head->Get();
	this->Pop();

	Queue<T> less, great;
	while (!this->Empty())
	{
		if (*head->Get() > *pattern)
		{
			less.Push(head->Get());
		}
		else
		{
			great.Push(head->Get());
		}
		this->Pop();
	}

	less.sort();
	great.sort();

	while (!less.Empty())
	{
		this->Push(less.Front());
		less.Pop();
	}

	this->Push(std::shared_ptr<T>(pattern));

	while (!great.Empty())
	{
		this->Push(great.Front());
		great.Pop();
	}
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

#include "figure.h"
template class
Queue<Figure>;
template
std::ostream& operator<<(std::ostream& os, const Queue<Figure> &obj);
/*
template class
Queue<int>;
template
std::ostream& operator<<(std::ostream& os, const Queue<int> &obj);
*/