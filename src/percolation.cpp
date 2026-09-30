#include "percolation.h"

Percolation::Percolation(std::size_t n) : uf(n * n + 2) {
        for (std::size_t i = 0; i < n; i++) {
                this->uf.connect(i + 1, 0);
                this->uf.connect((n - 1) * n + 1 + i, n * n + 1);
        }
}
