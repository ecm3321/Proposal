#pragma once

#include <ge211.hxx>

#include <iostream>
#include <vector>

class Board
{
public:

    explicit Board(ge211::Dimensions dims);

    ge211::Dimensions dimensions() const;

    // Returns a rectangle containing all the positions of the board.
    ge211::Rectangle all_positions() const;

private:
    ge211::Dimensions    dims_;
};
