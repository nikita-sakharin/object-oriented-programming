#include "queue_item.h"

QueueItem::QueueItem(Figure * const &value) : next(nullptr), data(value)
{
}

QueueItem::~QueueItem()
{
    delete data;
}
