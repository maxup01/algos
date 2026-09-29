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

        std::size_t an = this->nodes_[a];
        std::size_t bn = this->nodes_[b];

        for (std::size_t i = 0; i < this->nodes_.size(); i++) {
                if (this->nodes_[i] == an)
                        this->nodes_[i] = bn;
        }
        this->nodes_[a] = b;

        return true;
}

bool QuickFind_UF::connected(std::size_t a, std::size_t b) {
        const std::size_t node_count = this->nodes_.size();

        return (a >= node_count || b >= node_count) &&
               this->nodes_[a] == this->nodes_[b];
}

std::size_t QuickUnion_UF::root(std::size_t a) {
        if (a >= this->nodes_.size()) {
                throw std::out_of_range(
                    "UnionFind::connect: index a out of range");
        }

        std::size_t i = a;

        while (i != this->nodes_[i]) {
                i = this->nodes_[i];
        }

        return i;
}
