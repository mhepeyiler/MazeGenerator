#ifndef ORIENSPACE_H_
#define ORIENSPACE_H_

#include <map>
#include <utility>

namespace OrienSpace
{
    
    enum class Direction : unsigned int
    {
        N = 1,
        S = 2,
        E = 4,
        W = 8
    };

    using pair_dir_int = std::pair<Direction,int>;
    using pair_dir_dir = std::pair<Direction,Direction>;
    const std::map<Direction, int> kDX {pair_dir_int{E,1},
                                        pair_dir_int{W,-1},
                                        pair_dir_int{N,0},
                                        pair_dir_int{S,0}};

    const std::map<Direction, int> kDY {pair_dir_int{E,0},
                                        pair_dir_int{W,0},
                                        pair_dir_int{N,-1},
                                        pair_dir_int{S,1};

    const std::map<Direction, Direction> kOPPOSITE {    pair_dir_dir{E,W},
                                                        pair_dir_dir{W,E},
                                                        pair_dir_dir{N,S},
                                                        pair_dir_dir{S,N}};
}

#endif