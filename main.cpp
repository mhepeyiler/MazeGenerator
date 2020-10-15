#include <iostream>
#include <iterator>
#include <algorithm>
#include "MazeFactory.h"
#include "RecursiveDivision.h"
#include "BinaryTree.h"
int main()
{
    size_t sz{};
    std::cout << "Please enter dim of grid : ";
    //std::cin >> sz;

    auto grid = CreateGrid::getInstance(static_cast<size_t>(5));
    auto maze = MazeFactory<BinaryTree>::create();
    
    maze->Generate(grid);
    std::cout << grid;
    
    CreateGrid::del(grid);
    MazeFactory<BinaryTree>::del(maze);
    
    return 0;
}