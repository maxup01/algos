#include "randqueue.h"
#include <random>
#include <stdexcept>
#include <utility>

namespace {

size_t randomIndex(size_t count) {
        static std::mt19937 rng{std::random_device{}()};

        std::uniform_int_distribution<size_t> pick(0, count - 1);

        return pick(rng);
}

} // namespace

template <typename T> RandomizedQueue<T>::RandomizedQueue() {
        this->first = nullptr;
        this->node_count = 0;
}

template <typename T> bool RandomizedQueue<T>::isEmpty() {
        return 0 == this->node_count;
}

template <typename T> size_t RandomizedQueue<T>::size() {
        return this->node_count;
}

template <typename T> void RandomizedQueue<T>::enqueue(T item) {
        linkedList::QueueNode<T> *node =
            new linkedList::QueueNode<T>(std::move(item), this->first);

        this->first = node;

        this->node_count++;
}

template <typename T> T RandomizedQueue<T>::dequeue() {
        if (0 == this->node_count) {
                throw std::out_of_range(
                    "RandomizedQueue::dequeue: empty queue");
        }

        const size_t index = randomIndex(this->node_count);

        linkedList::QueueNode<T> **link = &this->first;

        for (size_t i = 0; i < index; i++) {
                link = &(*link)->next;
        }

        linkedList::QueueNode<T> *node = *link;

        *link = node->next;

        T item = std::move(node->item);

        delete node;

        this->node_count--;

        return item;
}

template <typename T> T RandomizedQueue<T>::sample() {
        if (0 == this->node_count) {
                throw std::out_of_range("RandomizedQueue::sample: empty queue");
        }

        const size_t index = randomIndex(this->node_count);

        linkedList::QueueNode<T> *node = this->first;

        for (size_t i = 0; i < index; i++) {
                node = node->next;
        }

        return node->item;
}
