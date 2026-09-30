#ifndef PERCOLATION_H
#define PERCOLATION_H

#include "union_find.h"
#include <stddef.h>
#include <vector>

enum CellStatus { OPEN, FULL };

class Percolation {
        WeightedQuickUnion_UF uf;
        std::size_t grid_size;
        std::vector<CellStatus> cells_status;

      public:
        Percolation(std::size_t n);
        void open(std::size_t row, std::size_t col);
        bool isOpen(std::size_t row, std::size_t col);
        bool isFull(std::size_t row, std::size_t col);
        bool percolates();
};

#endif
