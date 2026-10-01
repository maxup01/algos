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
        std::size_t open_cells_count;

      public:
        Percolation(std::size_t n);
        void open(std::size_t row, std::size_t col);
        bool isOpen(std::size_t row, std::size_t col);
        bool isFull(std::size_t row, std::size_t col);
        std::size_t numberOfOpenSites();
        bool percolates();
};

class PercolationStats {
        double mean_;
        double stddev_;
        double confidence_lo_;
        double confidence_hi_;

      public:
        PercolationStats(std::size_t n, std::size_t trials);

        double mean() const { return mean_; }
        double stddev() const { return stddev_; }
        double confidenceLo() const { return confidence_lo_; }
        double confidenceHi() const { return confidence_hi_; }
};

#endif
