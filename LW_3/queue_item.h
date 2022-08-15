#ifndef _QUEUE_ITEM_H_
#define _QUEUE_ITEM_H_

#include <memory>
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"

class QueueItem
{
	std::shared_ptr<Pentagon> pentagon;
	std::shared_ptr<Hexagon> hexagon;
	std::shared_ptr<Octagon> octagon;
	std::shared_ptr<QueueItem> next;

public:
	QueueItem(const std::shared_ptr<Pentagon> &pentagon_figure, const std::shared_ptr<Hexagon> &hexagon_figure, const std::shared_ptr<Octagon> &octagon_figure, const std::shared_ptr<QueueItem> &node);

	void SetPentagon(std::shared_ptr<Pentagon> &figure);
	void SetHexagon(std::shared_ptr<Hexagon> &figure);
	void SetOctagon(std::shared_ptr<Octagon> &figure);

	std::shared_ptr<Pentagon> GetPentagon() const;
	std::shared_ptr<Hexagon> GetHexagon() const;
	std::shared_ptr<Octagon> GetOctagon() const;

	void SetNext(std::shared_ptr<QueueItem> &node);
	std::shared_ptr<QueueItem> GetNext() const;

	friend std::ostream& operator<<(std::ostream& os, const QueueItem& obj);

	~QueueItem();
};
#endif