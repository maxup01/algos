#include "queue.h"

template <typename T>
linkedList::QueueNode<T>::QueueNode(T item, QueueNode<T> *next) {
        this->item = std::move(item);
        this->next = next;
}

template <typename T> linkedList::Queue<T>::Queue() {
        this->first_node = nullptr;
}
