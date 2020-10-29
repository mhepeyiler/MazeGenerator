#ifndef MAZE_H_
#define MAZE_H_

#include <vector>
#include <memory>
#include "Grid.h"

class Maze
{
public:
    virtual void Generate(Grid&) = 0;
};

#endif