#include "stack.h"

template <typename T>
linkedList::StackNode<T>::StackNode(T item, StackNode<T> *prev) {
        this->item = std::move(item);
        this->prev = prev;
}

template <typename T> linkedList::Stack<T>::Stack() {
        this->top_node = nullptr;
}

template <typename T> void linkedList::Stack<T>::push(T item) {
        StackNode<T> *node = new StackNode<T>(item, this->top_node);

        this->top_node = node;
}

template <typename T> std::optional<T> linkedList::Stack<T>::pop() {
        if (nullptr == this->top_node) {
                return std::nullopt;
        }

        StackNode<T> *node = this->top_node;

        this->top_node = node->prev;

        T item = std::move(node->item);

        free(node);

        return item;
}
