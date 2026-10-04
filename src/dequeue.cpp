#include "dequeue.h"
#include <stdlib.h>

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

template <typename T> bool Dequeue<T>::isEmpty() {
        return 0 == this->node_count;
}

template <typename T> void Dequeue<T>::addFirst(T item) {
        DequeueNode<T> *node = calloc(1, sizeof(DequeueNode<T>));
        node->item = item;

        this->first_node->prev = node;

        node->next = this->first_node;
        node->next->prev = node;

        this->first_node = node;

        if (nullptr == this->last_node) {
                this->last_node = node;
        }

        this->node_count++;
}

template <typename T> void Dequeue<T>::addLast(T item) {
        DequeueNode<T> *node = calloc(1, sizeof(DequeueNode<T>));
        node->item = item;

        this->last_node->next = node;

        node->prev = this->last_node;
        node->prev->next = node;

        this->last_node = node;

        if (nullptr == this->first_node) {
                this->first_node = node;
        }

        this->node_count++;
}

template <typename T> std::optional<T> Dequeue<T>::removeFirst() {
        if (nullptr == this->first_node) {
                return std::nullopt;
        }

        DequeueNode<T> *node = this->first_node;

        this->first_node = node->next;

        if (nullptr == this->first_node) {
                this->last_node = nullptr;
        } else {
                this->first_node->prev = nullptr;
        }

        T item = std::move(node->item);

        free(node);

        this->node_count--;

        return item;
}

template <typename T> std::optional<T> Dequeue<T>::removeLast() {
        if (nullptr == this->last_node) {
                return std::nullopt;
        }

        DequeueNode<T> *node = this->last_node;

        this->last_node = node->prev;

        if (nullptr == this->last_node) {
                this->first_node = nullptr;
        } else {
                this->last_node->next = nullptr;
        }

        T item = std::move(node->item);

        free(node);

        this->node_count--;

        return item;
}

template <typename T> DequeueIterator<T>::DequeueIterator(DequeueNode<T> *ptr) {
        this->first_node = ptr;
        this->next_node = ptr;
}

template <typename T> bool DequeueIterator<T>::hasNext() {
        return nullptr != this->next_node;
}

template <typename T> std::optional<T *> DequeueIterator<T>::next() {
        if (nullptr == this->next_node) {
                return std::nullopt;
        }

        T *item = &this->next_node->item;

        this->next_node = this->next_node->next;

        return item;
}
