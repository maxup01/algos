#include "union_find.h"

UnionFindNode *union_find_node_create(const uint64_t number) {
        UnionFindNode *node = calloc(0, sizeof(UnionFindNode));

        if (!node) {
                return NULL;
        }

        node->number = number;
        return node;
}

int union_find_init(UnionFind *uf) {
        uf = calloc(0, sizeof(UnionFind));
        return uf ? 0 : -1;
}
