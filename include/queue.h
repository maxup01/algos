#ifndef QUEUE_H
#define QUEUE_H

#include <optional>

namespace linkedList {

template <typename T> struct QueueNode {
        T item;
        QueueNode *next;

        QueueNode(T item, QueueNode *prev);
};

template <typename T> struct Queue {};

} // namespace linkedList

#endif
