#ifndef RANDOM_HELPER_H_
#define RANDOM_HELPER_H_

#include <random>


inline size_t Random(size_t val)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0,val);
    return static_cast<size_t>(distrib(gen));
}

inline bool Random()
{
    return static_cast<bool>(Random(1));
}


#endif