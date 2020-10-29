#ifndef GRID_H_
#define GRID_H_

#include <iosfwd>
#include <vector>

class Grid
{
public:
    static Grid& getInstance(size_t sz = msize);
    static size_t getSize();
    int& operator()(size_t i, size_t j);
    friend std::ostream& operator<<(std::ostream&os, Grid& gr);

private:
    Grid(size_t sz);
    static inline size_t msize{};
    std::vector<std::vector<int>> vec;

};


#endif