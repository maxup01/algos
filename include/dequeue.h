#ifndef DEQUEUE_H
#define DEQUEUE_H

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
};

#endif
