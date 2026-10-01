#include "queue.h"

template <typename T>
linkedList::QueueNode<T>::QueueNode(T item, QueueNode<T> *next) {
        this->item = std::move(item);
        this->next = next;
}
