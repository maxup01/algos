#ifndef RANDQUEUE_H
#define RANDQUEUE_H

#include "queue.h"
#include <stddef.h>

template <typename T> class RandomizedQueue {
        linkedList::QueueNode<T> *first;
        size_t node_count;

      public:
        RandomizedQueue();
        bool isEmpty();
        size_t size();
        void enqueue(T item);
        T dequeue();
        T sample();
        linkedList::QueueIterator<T> iterator();
};

#endif
