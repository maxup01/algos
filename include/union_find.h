#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>

class UnionFind {
      protected:
        std::vector<std::size_t> nodes_;

      public:
        UnionFind(std::size_t nodes_count);
        void add();

        virtual bool connect(std::size_t a, std::size_t b) = 0;
        virtual bool connected(std::size_t a, std::size_t b) = 0;
};

class QuickFind_UF : public UnionFind {
      public:
        bool connect(std::size_t a, std::size_t b) override;
        bool connected(std::size_t a, std::size_t b) override;
};

class QuickUnion_UF : public UnionFind {
        std::size_t root(std::size_t a);
};

#endif
