#include "union_find.h"

UnionFind::UnionFind(std::size_t nodes_count) : nodes_(nodes_count) {
        for (std::size_t i = 0; i < this->nodes_.size(); i++) {
                nodes_[i] = i;
        }
}

void UnionFind::add() { this->nodes_.push_back(this->nodes_.size()); }
