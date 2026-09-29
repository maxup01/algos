#include "union_find.h"

UnionFind::UnionFind(std::size_t nodes_count) : nodes_(nodes_count) {}

void UnionFind::add() { this->nodes_.push_back(this->nodes_.size()); }
