#pragma once

#include "model.hxx"
#include <ge211.hxx>

#include <string>

extern ge211::Color const light_color, dark_color;

extern int const grid_size;

class View
{
public:
    explicit View(Model const&);

    // You will probably want to add arguments here so that the
    // controller can communicate UI state (such as a mouse or
    // cursor position):
    void draw(ge211::Sprite_set&, Model);

    ge211::Dimensions initial_window_dimensions() const;

    std::string initial_window_title() const;

    ge211::Position board_to_screen_(ge211::Position) const;
    ge211::Position screen_to_board(ge211 :: Position) const;
    void move_piece_(ge211::Sprite_set&, Player, ge211::Position, int) const;

private:
    Model const& model_;


    ge211::Circle_sprite const pocket_{pocket_radius, dark_color};
    ge211::Rectangle_sprite const source_{store_dims, dark_color};
    ge211::Circle_sprite const piece_{piece_radius, light_color};
    ge211::Text_sprite store_number_{"Score:", {"sans.tff",30}};
    ge211::Text_sprite pocket_number_{"", {"sans.tff",30}};

};
