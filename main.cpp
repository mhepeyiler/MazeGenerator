#include <iostream>
#include <iterator>
#include <algorithm>
#include "MazeFactory.h"
#include "RecursiveDivision.h"
#include "CreateGrid.h"


int main()
{
    size_t sz{};
    std::cout << "Please enter dim of grid : ";
    std::cin >> sz;

    auto grid = CreateGrid::getInstance(static_cast<size_t>(sz));
    auto maze = MazeFactory<RecursiveDivision>::create();
    
    
    maze->Generate(grid);
    std::cout << grid;
    
    CreateGrid::del(grid);
    MazeFactory<RecursiveDivision>::del(maze);
    
    return 0;
}