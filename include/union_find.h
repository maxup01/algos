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
        virtual bool connected(std::size_t a, std::size_t b) const = 0;
};

class QuickFind_UF : UnionFind {
      public:
        bool connect(std::size_t a, std::size_t b) override;
};

#endif
