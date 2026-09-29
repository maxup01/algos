#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>

class UnionFind {
        std::vector<uint64_t> nodes_;

      public:
        UnionFind(std::size_t nodes_count);
        void add();

        virtual bool connect(std::uint64_t a, std::uint64_t b) = 0;
        virtual bool connected(std::uint64_t a, std::uint64_t b) const = 0;
};

class QuickFind_UF : UnionFind {};

#endif
