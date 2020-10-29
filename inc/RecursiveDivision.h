#ifndef RECURSIVE_DIVISION_H_
#define RECURSIVE_DIVISION_H_
#include "Maze.h"
#include <limits>

constexpr auto SIZE_T_MAX = std::numeric_limits<size_t>::max();

class RecursiveDivision : public Maze
{
public:
    void Generate(Grid& ) override;
private:
    enum class Orientation : bool
    {
        HORIZONTAL = false,
        VERTICAL = true
    };
    
    enum class Direction : bool
    {
        SOUTH = false,
        EAST = true
    };

    struct Point
    {
        size_t mx = 0;
        size_t my = 0;
    };

    struct PhyPro // physical properties - height/width
    {
        size_t mwidth = 0;
        size_t mheight = 0;
        PhyPro& operator=(const PhyPro& other);
        bool operator==(const PhyPro&);
        
    };

    friend Orientation ChooseOrientation(PhyPro);
    void Divide(Grid& , Point, PhyPro = PhyPro{SIZE_T_MAX, SIZE_T_MAX});
    PhyPro mdim;
    
};

#endif