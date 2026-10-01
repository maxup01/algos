#ifndef QUEUE_H
#define QUEUE_H

#include <optional>

namespace linkedList {

template <typename T> struct QueueNode {
        T item;
        QueueNode *next;

        QueueNode(T item, QueueNode *prev);
};

template <typename T> class Queue {
        QueueNode<T> *first_node;
        QueueNode<T> *last_node;

      public:
        Queue();
        void insert(T item);
};

} // namespace linkedList

#endif
