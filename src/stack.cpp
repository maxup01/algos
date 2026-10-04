#include "stack.h"

template <typename T>
linkedList::StackNode<T>::StackNode(T item, StackNode<T> *prev) {
        this->item = std::move(item);
        this->prev = prev;
}

template <typename T>
linkedList::StackIterator<T>::StackIterator(StackNode<T> *ptr) {
        this->top_node = ptr;
        this->next_node = ptr;
}

template <typename T> bool linkedList::StackIterator<T>::hasNext() {
        return nullptr != this->next_node;
}

template <typename T> std::optional<T *> linkedList::StackIterator<T>::next() {
        if (nullptr == this->next_node) {
                return std::nullopt;
        }

        T *item = &this->next_node->item;

        this->next_node = this->next_node->prev;

        return item;
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

template <typename T> bool linkedList::Stack<T>::isEmpty() const {
        return nullptr == this->top_node;
}

template <typename T>
linkedList::StackIterator<T> linkedList::Stack<T>::iterator() {
        return linkedList::StackIterator<T>(this->top_node);
}

template <typename T> array::StackNode<T>::StackNode(T item, int next) {
        this->item = item;
        this->next = next;
}

template <typename T>
array::StackIterator<T>::StackIterator(std::vector<StackNode<T>> *nodes,
                                       int top_node) {
        this->nodes = nodes;
        this->top_node = top_node;
        this->next_node = top_node;
}

template <typename T> bool array::StackIterator<T>::hasNext() {
        return -1 != this->next_node;
}

template <typename T> std::optional<T *> array::StackIterator<T>::next() {
        if (-1 == this->next_node) {
                return std::nullopt;
        }

        StackNode<T> &node =
            (*this->nodes)[static_cast<std::size_t>(this->next_node)];

        this->next_node = node.next;

        return &node.item;
}

template <typename T>
array::Stack<T>::Stack() : nodes(), top_node(-1), free_slots() {}

template <typename T> void array::Stack<T>::push(T item) {
        int slot;

        if (std::optional<int> reused = this->free_slots.take()) {
                slot = *reused;
                this->nodes[static_cast<std::size_t>(slot)] =
                    StackNode<T>(std::move(item), this->top_node);
        } else {
                slot = static_cast<int>(this->nodes.size());
                this->nodes.emplace_back(std::move(item), this->top_node);
        }

        this->top_node = slot;
}

template <typename T> std::optional<T> array::Stack<T>::pop() {
        if (-1 == this->top_node) {
                return std::nullopt;
        }

        const int slot = this->top_node;
        StackNode<T> &node = this->nodes[static_cast<std::size_t>(slot)];

        this->top_node = node.next;

        T item = std::move(node.item);
        node.next = -1;

        this->free_slots.insert(slot);

        return item;
}

template <typename T> bool array::Stack<T>::isEmpty() const {
        return -1 == this->top_node;
}

template <typename T> array::StackIterator<T> array::Stack<T>::iterator() {
        return array::StackIterator<T>(&this->nodes, this->top_node);
}
