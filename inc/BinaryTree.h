#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include "Maze.h"
#include "CreateGrid.h"
#include <map>
#include <utility>

class BinaryTree : public Maze
{

public:
    void Generate(CreateGrid*)override;
private:
    enum class Direction
    {
        NORTH=1,
        SOUTH=2,
        EAST=4,
        WEST=8
    };
    const std::map<Direction, int> kmDX{std::pair<Direction,int>{Direction::NORTH,0},
                                        std::pair<Direction,int>{Direction::SOUTH,0},
                                        std::pair<Direction,int>{Direction::EAST,1},
                                        std::pair<Direction,int>{Direction::WEST,-1}};

    const std::map<Direction, int> kmDY{std::pair<Direction,int>{Direction::NORTH,-1},
                                        std::pair<Direction,int>{Direction::SOUTH,1},
                                        std::pair<Direction,int>{Direction::EAST,0},
                                        std::pair<Direction,int>{Direction::WEST,0}};
                                        
    const std::map<Direction, Direction> kmOpposite{std::pair<Direction,Direction>{Direction::NORTH,Direction::SOUTH},
                                                    std::pair<Direction,Direction>{Direction::SOUTH,Direction::NORTH},
                                                    std::pair<Direction,Direction>{Direction::WEST,Direction::EAST},
                                                    std::pair<Direction,Direction>{Direction::EAST,Direction::WEST}};



};


#endif