#ifndef STACK_H
#define STACK_H

namespace linkedList {

template <typename T> struct StackNode {
        T item;
        StackNode *prev;
};

class Stack {};
} // namespace linkedList

#endif
