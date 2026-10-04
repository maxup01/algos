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
        this->node_count = 0;
}

template <typename T> size_t Dequeue<T>::size() { return this->node_count; }
