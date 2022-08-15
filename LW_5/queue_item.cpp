#include <iostream>
#include <memory>
#include "queue_item.h"

template <class First, class Second, class Third>
QueueItem<First, Second, Third>::QueueItem(const std::shared_ptr<First> &first_figure, const std::shared_ptr<Second> &second_figure, const std::shared_ptr<Third> &third_figure)
{
	first = first_figure;
	second = second_figure;
	third = third_figure;
	next = nullptr;
}

template <class First, class Second, class Third>
void QueueItem<First, Second, Third>::SetFirst(std::shared_ptr<First> &figure)
{
	first = figure;
}

template <class First, class Second, class Third>
void QueueItem<First, Second, Third>::SetSecond(std::shared_ptr<Second> &figure)
{
	second = figure;
}

template <class First, class Second, class Third>
void QueueItem<First, Second, Third>::SetThird(std::shared_ptr<Third> &figure)
{
	third = figure;
}

template <class First, class Second, class Third>
std::shared_ptr<First> QueueItem<First, Second, Third>::GetFirst() const
{
	return first;
}

template <class First, class Second, class Third>
std::shared_ptr<Second> QueueItem<First, Second, Third>::GetSecond() const
{
	return second;
}

template <class First, class Second, class Third>
std::shared_ptr<Third> QueueItem<First, Second, Third>::GetThird() const
{
	return third;
}

template <class First, class Second, class Third>
void QueueItem<First, Second, Third>::SetNext(std::shared_ptr<QueueItem<First, Second, Third>> &node)
{
	next = node;
}

template <class First, class Second, class Third>
std::shared_ptr<QueueItem<First, Second, Third>> QueueItem<First, Second, Third>::GetNext() const
{
	return next;
}

template <class First, class Second, class Third>
std::ostream& operator<<(std::ostream& os, const QueueItem<First, Second, Third>& obj)
{
	os << "First " << *obj.first;
	os << "Second " << *obj.second;
	os << "Third " << *obj.third;

	return os;
}

template <class First, class Second, class Third>
QueueItem<First, Second, Third>::~QueueItem()
{
}

#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"

template class
QueueItem<Pentagon, Hexagon, Octagon>;
template
std::ostream& operator<<(std::ostream& os, const QueueItem<Pentagon, Hexagon, Octagon>& obj);