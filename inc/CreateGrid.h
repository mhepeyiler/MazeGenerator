#ifndef CREATEGRID_H_
#define CREATEGRID_H_

#include <vector>
#include <exception>
#include <ostream>
#include <iostream>

class CreateGrid
{
public:
    static CreateGrid* getInstance(size_t sz)
    {
        msize = sz;
        if(!instance)
            instance = new CreateGrid(sz);
        return instance;    
    }

    static CreateGrid* getInstance()
    {
        return instance;    
    }

    static size_t getSize()
    {
        return msize;
    }

    int& operator()(size_t i, size_t j)
    {
            return vec.at(i).at(j);
    }

    friend std::ostream& operator<<(std::ostream&os, CreateGrid* gr)
    {
        for(size_t i = 0; i<gr->getSize(); ++i)
        {
            for(size_t j = 0; j<gr->getSize(); ++j)
            {
                os << gr->operator()(i,j) << ' ';
            }
            os << '\n';
        }
        return os;
    }

    static void del(CreateGrid* obj)
    {
        delete obj;
    }

private:
    CreateGrid() = delete;
    CreateGrid(size_t sz) : vec{std::vector<std::vector<int>>(sz, std::vector<int>(sz,0))} {}

    static inline size_t msize{};
    static inline CreateGrid* instance{};
    
    std::vector<std::vector<int>> vec;
};


#endif