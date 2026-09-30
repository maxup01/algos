#include "percolation.h"

Percolation::Percolation(std::size_t n)
    : uf(n * n + 2), cells_status(n * n, FULL) {
        for (std::size_t i = 0; i < n; i++) {
                this->uf.connect(i + 1, 0);
                this->uf.connect((n - 1) * n + 1 + i, n * n + 1);
        }
}

void Percolation::open(std::size_t row, std::size_t col) {
        std::size_t cell = (row - 1) * this->grid_size + col - 1;
        this->cells_status[cell - 1] = OPEN;

        if (0 != cell % this->grid_size) {
                uf.connect(cell, cell + 1);
        }

        if (0 != (cell - 1) % this->grid_size) {
                uf.connect(cell, cell - 1);
        }

        if (cell <= (this->grid_size - 1) * this->grid_size) {
                uf.connect(cell, cell + this->grid_size);
        }

        if (cell > this->grid_size) {
                uf.connect(cell, cell - this->grid_size);
        }
}

bool Percolation::isOpen(std::size_t row, std::size_t col) {
        return this->cells_status[(row - 1) * this->grid_size + col - 1] ==
               OPEN;
}

bool Percolation::isFull(std::size_t row, std::size_t col) {
        return this->cells_status[(row - 1) * this->grid_size + col - 1] ==
               FULL;
}

bool Percolation::percolates() {
        return this->uf.connected(0, this->grid_size * this->grid_size + 1);
}
