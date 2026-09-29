#include "union_find.h"

UnionFind::UnionFind(std::size_t nodes_count) : nodes_(nodes_count) {
        for (std::size_t i = 0; i < this->nodes_.size(); i++) {
                nodes_[i] = i;
        }
}

void UnionFind::add() { this->nodes_.push_back(this->nodes_.size()); }

bool QuickFind_UF::connect(std::size_t a, std::size_t b) {
        const std::size_t node_count = this->nodes_.size();

        if (a >= node_count || b >= node_count) {
                return false;
        }

        this->nodes_[a] = b;

        return true;
}
