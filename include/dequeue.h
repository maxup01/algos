#ifndef DEQUEUE_H
#define DEQUEUE_H

template <typename T> struct DequeueNode {
        T item;
        DequeueNode<T> *next;
        DequeueNode<T> *prev;
};

#endif
