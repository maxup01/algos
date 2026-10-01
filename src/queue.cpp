#include "queue.h"

template <typename T>
linkedList::QueueNode<T>::QueueNode(T item, QueueNode<T> *next) {
        this->item = std::move(item);
        this->next = next;
}

template <typename T> linkedList::Queue<T>::Queue() {
        this->first_node = nullptr;
        this->last_node = nullptr;
}

template <typename T> void linkedList::Queue<T>::insert(T item) {
        linkedList::QueueNode<T> *node =
            new linkedList::QueueNode<T>(std::move(item), nullptr);

        this->last_node->next = node;
        this->last_node = node;
}

template <typename T> std::optional<T> linkedList::Queue<T>::take() {
        if (nullptr == this->first_node) {
                return std::nullopt;
        }

        if (this->last_node == this->first_node) {
                this->last_node = nullptr;
        }

        QueueNode<T> *node = this->first_node;

        this->first_node = node->next;

        T item = std::move(node->item);

        free(node);

        return item;
}

template <typename T> array::QueueNode<T>::QueueNode(T item, int next) {
        this->item = std::move(item);
        this->next = next;
}

template <typename T> array::Queue<T>::Queue() : nodes() {
        this->first_node = 0;
        this->last_node = 0;
}
