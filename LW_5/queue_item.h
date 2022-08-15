#ifndef _QUEUE_ITEM_H_
#define _QUEUE_ITEM_H_

#include <iostream>
#include <memory>

template <class First, class Second, class Third>
class QueueItem
{
	std::shared_ptr<First> first;
	std::shared_ptr<Second> second;
	std::shared_ptr<Third> third;
	std::shared_ptr<QueueItem<First, Second, Third>> next;

public:
	QueueItem(const std::shared_ptr<First> &first_figure, const std::shared_ptr<Second> &second_figure, const std::shared_ptr<Third> &third_figure);

	void SetFirst(std::shared_ptr<First> &figure);
	void SetSecond(std::shared_ptr<Second> &figure);
	void SetThird(std::shared_ptr<Third> &figure);

	std::shared_ptr<First> GetFirst() const;
	std::shared_ptr<Second> GetSecond() const;
	std::shared_ptr<Third> GetThird() const;

	void SetNext(std::shared_ptr<QueueItem<First, Second, Third>> &node);
	std::shared_ptr<QueueItem<First, Second, Third>> GetNext() const;

	template <class A, class B, class C>
	friend std::ostream& operator<<(std::ostream& os, const QueueItem<A, B, C>& obj);

	~QueueItem();
};

#endif