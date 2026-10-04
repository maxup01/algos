#ifndef DEQUEUE_H
#define DEQUEUE_H

#include "iterator.h"
#include <optional>
#include <stddef.h>

template <typename T> struct DequeueNode {
        T item;
        DequeueNode<T> *prev;
        DequeueNode<T> *next;

        DequeueNode(T item, DequeueNode<T> *prev, DequeueNode<T> *next);
};

template <typename T> class Dequeue {
        DequeueNode<T> *first_node;
        DequeueNode<T> *last_node;
        size_t node_count;

      public:
        Dequeue();
        size_t size();
        bool isEmpty();
        void addFirst(T item);
        void addLast(T item);
        std::optional<T> removeFirst();
        std::optional<T> removeLast();
};

template <typename T> struct DequeueIterator : public Iterator<T> {
        DequeueNode<T> *first_node;
        DequeueNode<T> *next_node;

        DequeueIterator(DequeueNode<T> *ptr);
        bool hasNext() override;
        std::optional<T *> next() override;
};

#endif
