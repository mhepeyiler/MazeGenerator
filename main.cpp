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
    std::cin >> sz;
    auto grid = Grid::getInstance(sz);
    auto maze = MazeFactory<RecursiveDivision>();
    
    maze->Generate(grid);
    std::cout << grid;
    
    return 0;
}