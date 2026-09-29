#include "union_find.h"

int union_find_init(UnionFind *uf) {
        uf = calloc(0, sizeof(UnionFind));
        return uf != 0 ? 0 : -1;
}
