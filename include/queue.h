#ifndef QUEUE_H
#define QUEUE_H

#include <optional>

namespace linkedList {

template <typename T> struct QueueNode {
        T item;
        QueueNode *prev;

        QueueNode(T item, QueueNode *prev);
};
} // namespace linkedList

#endif
