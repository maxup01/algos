#ifndef STACK_H
#define STACK_H

#include <optional>
#include <vector>

#include "iterator.h"
#include "queue.h"

namespace linkedList {

template <typename T> struct StackNode {
        T item;
        StackNode *prev;

        StackNode(T item, StackNode *prev);
};

template <typename T> class Stack {
        StackNode<T> *top_node;

      public:
        Stack<T>();
        void push(T item);
        std::optional<T> pop();
        bool isEmpty() const;
};

template <typename T> struct StackIterator : public Iterator<T> {
        StackNode<T> *top_node;
        StackNode<T> *next_node;

        StackIterator(StackNode<T> *ptr);
        bool hasNext() override;
        std::optional<T *> next() override;
};
} // namespace linkedList

namespace array {

template <typename T> struct StackNode {
        T item;
        int next;

        StackNode(T item, int next);
};

template <typename T> class Stack {
        std::vector<StackNode<T>> nodes;
        int top_node;
        linkedList::Queue<int> free_slots;

      public:
        Stack();
        void push(T item);
        std::optional<T> pop();
        bool isEmpty() const;
};

template <typename T> struct StackIterator : public Iterator<T> {
        std::vector<StackNode<T>> *nodes;
        int top_node;
        int next_node;

        StackIterator(std::vector<StackNode<T>> *nodes, int top_node);
        bool hasNext() override;
        std::optional<T *> next() override;
};
} // namespace array

#endif
