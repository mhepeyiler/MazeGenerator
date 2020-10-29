#include "BinaryTree.h"
#include "RandomHelper.h"

void BinaryTree::Generate(Grid& grid)
{
    for(size_t i = 0; i<grid.getSize(); ++i)
    {
        for(size_t j = 0; j<grid.getSize(); ++j)
        {
            std::vector<Direction> dirs;
            if(i==0 && j == 0)
                break;
            if(i>0)
                dirs.push_back(Direction::NORTH);
            if(j>0)
                dirs.push_back(Direction::WEST);
            
            Direction dir = dirs[Random(dirs.size())];

            size_t nx = i + kmDX.find(dir)->second;
            size_t ny = j + kmDY.find(dir)->second;
            grid(i,j) |= static_cast<int>(dir);
            grid(ny, nx) |= static_cast<int>(kmOpposite.find(dir)->second);
        }
    }
}