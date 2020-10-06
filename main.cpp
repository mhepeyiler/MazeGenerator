#include <iostream>
#include <iterator>
#include <algorithm>
#include "MazeFactory.h"
#include "RecursiveDivision.h"
#include "CreateGrid.h"


int main()
{
    auto grid = CreateGrid::getInstance(20);
    auto maze = MazeFactory<RecursiveDivision>::create();
    maze->Generate(grid);
    std::cout << grid;
}