#ifndef STACK_H
#define STACK_H

namespace linkedList {

template <typename T> struct StackNode {
        T item;
        StackNode *prev;

        StackNode(T item, StackNode *prev);
};

template <typename T> class Stack {
        StackNode<T> *top_node;

        void push(T item);
};
} // namespace linkedList

#endif
