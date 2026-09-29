#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
        uint64_t number;
        struct UnionFindNode **linked_nodes;
} UnionFindNode;

UnionFindNode *union_find_node_create(const uint64_t number);

typedef struct {
        struct UnionFindNode **nodes;
} UnionFind;

int union_find_init(UnionFind *uf, const size_t count);

#endif
