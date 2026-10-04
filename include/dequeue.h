#ifndef DEQUEUE_H
#define DEQUEUE_H

template <typename T> struct DequeueNode {
        T item;
        DequeueNode<T> *prev;
        DequeueNode<T> *next;

        DequeueNode(T item, DequeueNode<T> *prev, DequeueNode<T> *next);
};

#endif
