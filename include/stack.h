#ifndef STACK_H
#define STACK_H

namespace linkedList {

template <typename T> struct StackNode {
        T item;
        StackNode *prev;
};

template <typename T> class Stack {
        StackNode<T> *top_node;
};
} // namespace linkedList

#endif
