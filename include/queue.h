#ifndef QUEUE_H
#define QUEUE_H

#include "iterator.h"
#include <optional>
#include <vector>

namespace linkedList {

template <typename T> struct QueueNode {
        T item;
        QueueNode *next;

        QueueNode(T item, QueueNode *prev);
};

template <typename T> class QueueIterator : public Iterator<T> {
        QueueNode<T> *first_node;
        QueueNode<T> *next_node;

      public:
        QueueIterator(QueueNode<T> *ptr);
        bool hasNext() override;
        std::optional<T *> next() override;
};

template <typename T> class Queue {
        QueueNode<T> *first_node;
        QueueNode<T> *last_node;

      public:
        Queue();
        void insert(T item);
        std::optional<T> take();
        bool isEmpty();
        QueueIterator<T> iterator();
};

} // namespace linkedList

namespace array {

template <typename T> struct QueueNode {
        T item;
        int next;

        QueueNode(T item, int next);
};

template <typename T> class QueueIterator : public Iterator<T> {
        std::vector<QueueNode<T>> *nodes;
        int first_node;
        int next_node;

      public:
        QueueIterator(std::vector<QueueNode<T>> *nodes, int first_node);
        bool hasNext() override;
        std::optional<T *> next() override;
};

template <typename T> class Queue {
        std::vector<QueueNode<T>> nodes;
        int first_node;
        int last_node;
        linkedList::Queue<std::size_t> free_slots;

      public:
        Queue();
        void insert(T item);
        std::optional<T> take();
        bool isEmpty();
        QueueIterator<T> iterator();
};
} // namespace array

#endif
