#ifndef PERCOLATION_H
#define PERCOLATION_H

#include <stddef.h>
#include <vector>

class Percolation {
        std::vector<std::size_t> cells;

      public:
        Percolation(std::size_t n);
};

#endif
