#ifndef PERCOLATION_H
#define PERCOLATION_H

#include <stddef.h>
#include <vector>

class Percolation {
        std::vector<std::size_t> cells;

      public:
        Percolation(std::size_t n);
        void open(std::size_t row, std::size_t col);
};

#endif
