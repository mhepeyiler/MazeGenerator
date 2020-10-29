#include "Grid.h"
#include <exception>
#include <ostream>
#include <iostream>

#define STATIC
#define PUBLIC
#define PRIVATE
#define FRIEND


PRIVATE Grid::Grid(size_t sz) : vec{std::vector<std::vector<int>>(sz, std::vector<int>(sz,0))} {}

STATIC PUBLIC Grid& Grid::getInstance(size_t sz)
{
    if(sz == 0)
        throw std::exception{};
    msize = sz;
    static Grid gr{sz};
    return gr;  
}

STATIC PUBLIC size_t Grid::getSize()
{
    return msize;
}

PUBLIC int& Grid::operator()(size_t i, size_t j)
{
    return vec.at(i).at(j);
}

FRIEND std::ostream& operator<<(std::ostream&os, Grid& gr)
{
    for(size_t i = 0; i<gr.getSize(); ++i)
    {
        for(size_t j = 0; j<gr.getSize(); ++j)
        {
            os << gr.operator()(i,j);
        }
        os << '\n';
    }
    return os;
}

