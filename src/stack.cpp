#include "stack.h"

template <typename T>
linkedList::StackNode<T>::StackNode(T item, StackNode<T> *prev) {
        this->item = item;
        this->prev = prev;
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

        T item = node->item;

        free(node);

        return item;
}
