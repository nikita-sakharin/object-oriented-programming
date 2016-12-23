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
void Stack<T>::Push(const T &element)
{
	StackItem<T> *temp = new StackItem<T>(element, head);
	head = temp;
	++count;
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
T &Stack<T>::Front()
{
	return head->Get();
}

template <class T>
void Stack<T>::Pop()
{
	if (head != nullptr)
	{
		StackItem<T> *temp = &head->GetNext();
		delete head;
		head = temp;
		--count;
	}
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

typedef unsigned char Byte;

template class
Stack<void *>;