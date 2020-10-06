#include "RecursiveDivision.h"
#include <random>


static bool Random()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0,1);
    return static_cast<bool>(distrib(gen));
}

static int Random(size_t val)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0,val);
    return static_cast<size_t>(distrib(gen));
}

void RecursiveDivision::Generate(CreateGrid* grid)
{
    mdim.mheight = grid->getSize();
    mdim.mwidth = grid->getSize();
    Divide(grid, Point{});
}

RecursiveDivision::Orientation ChooseOrientation(RecursiveDivision::PhyPro dim)
{
    if(dim.mwidth < dim.mheight)
        return RecursiveDivision::Orientation::HORIZONTAL;
    else if(dim.mwidth > dim.mheight)
        return RecursiveDivision::Orientation::VERTICAL;
    else
        return Random() ? RecursiveDivision::Orientation::HORIZONTAL : RecursiveDivision::Orientation::VERTICAL;
}

RecursiveDivision::PhyPro& RecursiveDivision::PhyPro::operator=(const RecursiveDivision::PhyPro& other)
{
    if(&other != this)
    {    
        mwidth = other.mwidth;
        mheight = other.mheight;
    }
    return *this;
}

bool RecursiveDivision::PhyPro::operator==(const PhyPro& other)
{
    return mheight == other.mheight && mwidth == other.mwidth;
}

void RecursiveDivision::Divide(CreateGrid* grid, Point point, PhyPro dim)
{
    // TODO : Check algorithm
    // It does not work properly
    // http://weblog.jamisbuck.org/2011/1/12/maze-generation-recursive-division-algorithm

    if(dim == PhyPro{SIZE_T_MAX, SIZE_T_MAX})
    {
        dim = mdim;
    }

    if(dim.mwidth < 2 || dim.mheight < 2) // Base case
        return;
    
    auto orientation_state = ChooseOrientation(dim) == Orientation::HORIZONTAL;
    
    //Wall points
    Point wall_point;
    wall_point.mx = point.mx + (orientation_state ? 0 : Random(dim.mwidth-2));
    wall_point.my = point.mx + (orientation_state ? Random(dim.mheight-2) : 0);

    //Passage through
    Point passage_point;
    passage_point.mx = wall_point.mx + (orientation_state ? Random(dim.mwidth) : 0);
    passage_point.my = wall_point.my + (orientation_state ? 0 : Random(dim.mheight));

    //Wall direction
    Point wall_dir;
    wall_dir.mx = (orientation_state ? 1 : 0);
    wall_dir.my = (orientation_state ? 0 : 1);

    //Length
    size_t length = (orientation_state ? dim.mwidth : dim.mheight);
    //Direction that perpendicular to wall
    Direction per_dir = (orientation_state ? Direction::SOUTH : Direction::EAST);

    for(size_t i = 0; i < length; ++i)
    {
        //wall_point.mx = wall_point.mx > mdim.mwidth-1 ? mdim.mwidth-1 : wall_point.mx;
        //wall_point.my = wall_point.my > mdim.mheight-1 ? mdim.mheight-1 : wall_point.my;
        grid->operator()(wall_point.mx, wall_point.my) |= (per_dir == Direction::SOUTH ? wall_point.mx != passage_point.mx : wall_point.my != passage_point.my);
        wall_point.mx += wall_dir.mx;
        wall_point.my += wall_dir.my;
    }

    PhyPro new_dim1;
    new_dim1.mwidth = (orientation_state ? dim.mwidth : wall_point.mx - point.mx + 1);
    new_dim1.mheight = (orientation_state ? point.my - point.my + 1 : dim.mheight);
    Divide(grid, point, new_dim1);

    Point new_point;
    new_point.mx = (orientation_state ? point.mx : wall_point.mx + 1);
    new_point.my = (orientation_state ? wall_point.my + 1 : point.my);
    
    PhyPro new_dim2;
    new_dim2.mwidth = (orientation_state ? dim.mwidth : point.mx + dim.mwidth - wall_point.mx - 1);
    new_dim2.mheight = (orientation_state ? point.my + dim.mheight - wall_point.my - 1 : dim.mheight);
    Divide(grid, new_point, new_dim2);
}