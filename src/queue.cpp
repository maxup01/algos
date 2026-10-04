#include "queue.h"

template <typename T>
linkedList::QueueNode<T>::QueueNode(T item, QueueNode<T> *next) {
        this->item = std::move(item);
        this->next = next;
}

template <typename T>
linkedList::QueueIterator<T>::QueueIterator(QueueNode<T> *ptr) {
        this->next_node = ptr;
        this->first_node = ptr;
}

template <typename T> bool linkedList::QueueIterator<T>::hasNext() {
        return nullptr != this->next_node;
}

template <typename T> std::optional<T *> linkedList::QueueIterator<T>::next() {
        if (nullptr == this->next_node) {
                return std::nullopt;
        }

        T *item = &this->next_node->item;

        this->next_node = this->next_node->next_node;

        return item;
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

template <typename T> bool linkedList::Queue<T>::isEmpty() {
        return nullptr == this->first_node;
}

template <typename T>
linkedList::QueueIterator<T> linkedList::Queue<T>::iterator() {
        return linkedList::QueueIterator<T>(this->first_node);
}

template <typename T> array::QueueNode<T>::QueueNode(T item, int next) {
        this->item = std::move(item);
        this->next = next;
}

template <typename T>
array::QueueIterator<T>::QueueIterator(std::vector<QueueNode<T>> *nodes,
                                       int first_node) {
        this->nodes = nodes;
        this->first_node = first_node;
        this->next_node = first_node;
}

template <typename T> bool array::QueueIterator<T>::hasNext() {
        return -1 != this->next_node;
}

template <typename T> std::optional<T *> array::QueueIterator<T>::next() {
        if (-1 == this->next_node) {
                return std::nullopt;
        }

        QueueNode<T> &node =
            (*this->nodes)[static_cast<std::size_t>(this->next_node)];

        this->next_node = node.next;

        return &node.item;
}

template <typename T> array::Queue<T>::Queue() : nodes(), free_slots() {
        this->first_node = -1;
        this->last_node = -1;
}

template <typename T> void array::Queue<T>::insert(T item) {
        int slot;

        if (std::optional<std::size_t> reused = this->free_slots.take()) {
                slot = *reused;
                this->nodes[static_cast<std::size_t>(slot)] =
                    QueueNode<T>(std::move(item), -1);
        } else {
                slot = static_cast<int>(this->nodes.size());
                this->nodes.push_back(std::move(item), -1);
        }

        if (-1 == this->last_node) {
                this->first_node = slot;
        } else {
                this->nodes[static_cast<std::size_t>(this->last_node)].next =
                    slot;
        }

        this->last_node = slot;
}

template <typename T> std::optional<T> array::Queue<T>::take() {
        if (this->first_node < 0) {
                return std::nullopt;
        }

        QueueNode<T> node = std::move(this->nodes[first_node]);

        if (this->first_node == this->last_node) {
                this->last_node = -1;
        }

        this->free_slots.insert(this->first_node);
        this->first_node = node.next;

        return std::move(node.item);
}

template <typename T> bool array::Queue<T>::isEmpty() {
        return -1 == this->first_node;
}

template <typename T> array::QueueIterator<T> array::Queue<T>::iterator() {
        return array::QueueIterator<T>(&this->nodes, this->first_node);
}
