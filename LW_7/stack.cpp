#include <iostream>
#include <memory>
#include "stack.h"

template <class T>
Stack<T>::Stack()
{
	head = nullptr;
	count = 0u;
}

template <class T>
void Stack<T>::Push(T &element)
{
	StackItem<T> *it_curr = head, *it_prev = head;

	while (it_curr != nullptr && element > it_curr->Get())
	{
		it_prev = it_curr;
		it_curr = &it_curr->GetNext();
	}

	StackItem<T> *new_temp = new StackItem<T>(element, it_curr);
	if (head == nullptr || it_curr == head)
	{
		head = new_temp;
	}
	else
	{
		it_prev->SetNext(new_temp);
	}

	++count;
}

template <class T>
T &Stack<T>::Front()
{
	return head->Get();
}

template <class T>
void Stack<T>::Pop(bool (*func)(const T &))
{
	StackItem<T> *it_curr = head, *it_prev = head;
	while (it_curr != nullptr)
	{
		if (func(it_curr->Get()))
		{
			if (it_curr == head)
			{
				head = &it_curr->GetNext();
				delete it_curr;
				it_curr = head;
			}
			else
			{
				it_prev->SetNext(&it_curr->GetNext());
				delete it_curr;
				it_curr = &it_prev->GetNext();
			}
			--count;
		}
		else
		{
			it_prev = it_curr;
			it_curr = &it_curr->GetNext();
		}
	}
}

template <class T>
bool Stack<T>::Empty() const
{
	return !count;
}

template <class T>
size_t Stack<T>::Size() const
{
	return count;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack)
{
	for (StackItem<T> *temp = stack.head, *local_temp; temp != nullptr; temp = local_temp)
	{
		local_temp = &temp->GetNext();
		os << *temp << "\n";
	}

	return os;
}

template <class T>
Stack<T>::~Stack()
{
	for (StackItem<T> *temp = head, *local_temp; temp != nullptr; temp = local_temp)
	{
		local_temp = &temp->GetNext();
		delete temp;
	}
}

#include "figure.h"
template class
Stack<Figure *>;
template
std::ostream& operator<<(std::ostream& os, const Stack<Figure *> &obj);
/*
template class
Stack<int>;
template
std::ostream& operator<<(std::ostream& os, const Stack<int> &obj);
*/