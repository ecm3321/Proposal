#include "board.hxx"
#include <algorithm>

using namespace ge211;

Board::Board(Dimensions dims)
        : dims_(dims)
{}

Dimensions Board::dimensions() const
{
    return dims_;
}

Rectangle Board::all_positions() const
{
    return Rectangle::from_top_left({0, 0}, dims_);
}