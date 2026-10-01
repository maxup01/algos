#ifndef QUEUE_H
#define QUEUE_H

#include <optional>
#include <vector>

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
        std::optional<T> take();
};

} // namespace linkedList

namespace array {

template <typename T> struct QueueNode {
        T item;
        int next;

        QueueNode(T item, int next);
};

template <typename T> class Queue {
        std::vector<QueueNode<T>> nodes;
        std::size_t first_node;
        std::size_t last_node;

        Queue();
};
} // namespace array

#endif
