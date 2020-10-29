#ifndef MAZEFACTORY_H_
#define MAZEFACTORY_H_
#include "Maze.h"
#include <type_traits>
#include <memory>


template<typename T>
std::enable_if_t<std::is_base_of_v<Maze, T>, std::unique_ptr<Maze>> MazeFactory()
{
    return std::make_unique<T>();
}


#endif