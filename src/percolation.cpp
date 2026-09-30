#include "percolation.h"

Percolation::Percolation(std::size_t n) {
        cells.reserve(n * n + 2);

        for (std::size_t i = 0; i < n * n + 2; i++) {
                this->cells.push_back(i);
        }

        for (std::size_t i = 0; i < n; i++) {
                this->cells[i + 1] = 0;
                this->cells[(n - 1) * n + 1 + i] = n * n + 1;
        }
}
