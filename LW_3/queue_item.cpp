#include <iostream>
#include "queue_item.h"

QueueItem::QueueItem(const std::shared_ptr<Pentagon> &pentagon_figure, const std::shared_ptr<Hexagon> &hexagon_figure, const std::shared_ptr<Octagon> &octagon_figure, const std::shared_ptr<QueueItem> &node)
{
	pentagon = pentagon_figure;
	hexagon = hexagon_figure;
	octagon = octagon_figure;
	next = node;
}

void QueueItem::SetPentagon(std::shared_ptr<Pentagon> &figure)
{
	pentagon = figure;
}

void QueueItem::SetHexagon(std::shared_ptr<Hexagon> &figure)
{
	hexagon = figure;
}

void QueueItem::SetOctagon(std::shared_ptr<Octagon> &figure)
{
	octagon = figure;
}

std::shared_ptr<Pentagon> QueueItem::GetPentagon() const
{
	return pentagon;
}

std::shared_ptr<Hexagon> QueueItem::GetHexagon() const
{
	return hexagon;
}

std::shared_ptr<Octagon> QueueItem::GetOctagon() const
{
	return octagon;
}

void QueueItem::SetNext(std::shared_ptr<QueueItem> &node)
{
	next = node;
}

std::shared_ptr<QueueItem> QueueItem::GetNext() const
{
	return next;
}

std::ostream& operator<<(std::ostream& os, const QueueItem& obj)
{
	os << "Pentagon" << *obj.pentagon;
	os << "Hexagon" << *obj.hexagon;
	os << "Octagon" << *obj.octagon;

	return os;
}

QueueItem::~QueueItem()
{
}