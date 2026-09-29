#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
        uint64_t number;
        struct UnionFindNode **linked_nodes;
} UnionFindNode;

UnionFindNode *union_find_node_create(const uint64_t number,
                                      const size_t linked_nodes_count);

typedef struct {
        UnionFindNode **nodes;
        size_t allocated_nodes;
        size_t node_count;
} UnionFind;

int union_find_init(UnionFind *uf, const size_t count);

int add(UnionFind *uf, const uint64_t number);

int connect(UnionFind *uf, const uint64_t f, const uint64_t s);

#endif
