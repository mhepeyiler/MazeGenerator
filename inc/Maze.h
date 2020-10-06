#ifndef MAZE_H_
#define MAZE_H_

#include <vector>
#include "CreateGrid.h"

class Maze
{
public:
    virtual void Generate(CreateGrid*) = 0;
};

#endif