#ifndef ITERATOR_H
#define ITERATOR_H

#include <optional>

template <typename T> class Iterator {
      public:
        virtual bool hasNext() = 0;
        virtual std::optional<T> next() = 0;
};

#endif
