#ifndef STACK_H
#define STACK_H

#include <optional>

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
};
} // namespace linkedList

namespace array {
template <typename T> struct StackNode {
        T item;
        int next;
};
} // namespace array

#endif
