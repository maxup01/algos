#include "union_find.h"

UnionFindNode *union_find_node_create(const uint64_t number,
                                      const size_t linked_nodes_count) {
        UnionFindNode *node = calloc(1, sizeof(UnionFindNode));

        if (0 == linked_nodes_count || !node) {
                return NULL;
        }

        node->number = number;
        node->linked_nodes =
            calloc(linked_nodes_count, sizeof(UnionFindNode *));

        if (!node->linked_nodes) {
                free(node);

                return NULL;
        }

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

int connect(UnionFind *uf, const uint64_t f, const uint64_t s) {
        if (!uf) {
                return -1;
        }

        return 0;
}
