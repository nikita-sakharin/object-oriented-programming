#ifndef _QUEUE_ITEM_H_
#define _QUEUE_ITEM_H_

#include "Figure.h"

class QueueItem
{
public:
	QueueItem *next;
	Figure *data;
	QueueItem(Figure * const &);
    ~QueueItem();
};

#endif
