#include "queue.h"

template <typename T>
linkedList::QueueNode<T>::QueueNode(T item, QueueNode<T> *prev) {
        this->item = std::move(item);
        this->prev = prev;
}
