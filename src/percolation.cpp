#include "percolation.h"

Percolation::Percolation(std::size_t n) {
        cells.reserve(n * n + 2);

        for (std::size_t i = 0; i < n * n + 2; i++) {
                this->cells.push_back(i);
        }
}
