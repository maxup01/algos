#include "union_find.h"

#define INITIAL_LINKED_NODE_COUNT 2

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

        uf->node_count = count;

        return 0;
}

int add(UnionFind *uf, const uint64_t number) {
        if (!uf) {
                return -1;
        }

        for (size_t i = 0; i < uf->node_count; i++) {
                if (number == ((UnionFindNode *)(uf->nodes + i))->number) {
                        return -1;
                }
        }

        if (uf->allocated_nodes == uf->node_count) {
                UnionFindNode **tmp = realloc(
                    uf->nodes, (uf->node_count + 4) * sizeof(UnionFindNode *));

                if (!tmp) {
                        return -1;
                }

                uf->nodes = tmp;
                uf->node_count += 4;
        }

        UnionFindNode *node =
            union_find_node_create(number, INITIAL_LINKED_NODE_COUNT);

        if (!node) {
                return -1;
        }

        uf->nodes[uf->allocated_nodes++] = node;

        return 0;
}

int connect(UnionFind *uf, const uint64_t f, const uint64_t s) {
        if (!uf) {
                return -1;
        }

        return 0;
}
