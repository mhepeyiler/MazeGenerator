#ifndef MAZEFACTORY_H_
#define MAZEFACTORY_H_
#include "Maze.h"
#include <type_traits>



template<typename T>
struct MazeFactory
{
    
    static std::enable_if_t<std::is_base_of_v<Maze, T>,Maze*> create() 
    {
        return new T; 
    }

    static std::enable_if_t<std::is_base_of_v<Maze, T>> del(Maze* obj)
    {
        delete obj;
    }
};

#endif