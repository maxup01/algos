#ifndef DEQUEUE_H
#define DEQUEUE_H

template <typename T> struct DequeueNode {
        T item;
        DequeueNode<T> *prev;
        DequeueNode<T> *next;

        DequeueNode(T item, DequeueNode<T> *prev, DequeueNode<T> *next);
};

template <typename T> class Dequeue {
        DequeueNode<T> *first_node;
        DequeueNode<T> *last_node;

      public:
        Dequeue();
};

#endif
