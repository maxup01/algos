#include "percolation.h"
#include <random>

std::size_t Percolation::index(std::size_t row, std::size_t col) {
        if (row < 1 || row > this->grid_size || col < 1 ||
            col > this->grid_size) {
                throw std::out_of_range(
                    "Percolation: row and col must be in [1, n]");
        }

        return (row - 1) * this->grid_size + (col - 1);
}

Percolation::Percolation(std::size_t n)
    : uf(n * n + 2), cells_status(n * n, FULL) {
        if (0 == n) {
                throw std::invalid_argument("n should be a positive number");
        }
}

void Percolation::open(std::size_t row, std::size_t col) {
        std::size_t cell = this->index(row, col);

        this->cells_status[cell - 1] = OPEN;
        this->open_cells_count += 1;

        if (0 != cell % this->grid_size) {
                uf.connect(cell, cell + 1);
        }

        if (0 != (cell - 1) % this->grid_size) {
                uf.connect(cell, cell - 1);
        }

        if (cell <= (this->grid_size - 1) * this->grid_size) {
                uf.connect(cell, cell + this->grid_size);
        } else {
                uf.connect(cell, this->grid_size * this->grid_size + 1);
        }

        if (cell > this->grid_size) {
                uf.connect(cell, cell - this->grid_size);
        } else {
                uf.connect(cell, 0);
        }
}

bool Percolation::isOpen(std::size_t row, std::size_t col) {
        return this->cells_status[this->index(row, col)] == OPEN;
}

bool Percolation::isFull(std::size_t row, std::size_t col) {
        return this->cells_status[this->index(row, col)] == FULL;
}

std::size_t Percolation::numberOfOpenSites() { return this->open_cells_count; }

bool Percolation::percolates() {
        return this->uf.connected(0, this->grid_size * this->grid_size + 1);
}

PercolationStats::PercolationStats(std::size_t n, std::size_t trials) {
        if (n == 0 || trials == 0) {
                throw std::invalid_argument(
                    "PercolationStats: n and trials must be > 0");
        }

        std::mt19937 rng{std::random_device{}()};
        std::uniform_int_distribution<std::size_t> pick(0, n - 1);

        std::vector<double> thresholds(trials);

        for (std::size_t t = 0; t < trials; t++) {
                Percolation p(n);

                while (!p.percolates()) {
                        std::size_t row = pick(rng);
                        std::size_t col = pick(rng);
                        if (!p.isOpen(row, col)) {
                                p.open(row, col);
                        }
                }

                thresholds[t] = static_cast<double>(p.numberOfOpenSites()) /
                                static_cast<double>(n * n);
        }
}
