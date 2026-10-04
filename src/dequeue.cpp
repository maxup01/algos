#include "dequeue.h"

template <typename T>
DequeueNode<T>::DequeueNode(T item, DequeueNode<T> *prev,
                            DequeueNode<T> *next) {
        this->item = item;
        this->prev = prev;
        this->next = next;
}

template <typename T> Dequeue<T>::Dequeue() {
        this->first_node = nullptr;
        this->last_node = nullptr;
}
