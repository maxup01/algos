#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <stdint.h>

typedef struct {
        uint64_t number;
        struct UnionFindNode **linked_nodes;
} UnionFindNode;

typedef struct {
        struct UnionFindNode **nodes;
} UnionFind;

#endif
