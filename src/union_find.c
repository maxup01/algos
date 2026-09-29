#include "union_find.h"

UnionFindNode *union_find_node_create(const uint64_t number) {
        UnionFindNode *node = calloc(1, sizeof(UnionFindNode));

        if (!node) {
                return NULL;
        }

        node->number = number;
        return node;
}

int union_find_init(UnionFind *uf, const size_t count) {
        if (!uf || 0 == count) {
                return -1;
        }

        uf->nodes = calloc(count, sizeof(UnionFindNode *));

        if (!uf->nodes) {
                free(uf);

                return -1;
        }

        return 0;
}
