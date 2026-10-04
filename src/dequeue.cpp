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
}
