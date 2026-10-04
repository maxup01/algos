#include "dequeue.h"

template <typename T>
DequeueNode<T>::DequeueNode(T item, DequeueNode<T> *prev,
                            DequeueNode<T> *next) {
        this->item = item;
        this->prev = prev;
        this->next = next;
}
