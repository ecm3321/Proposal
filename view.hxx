#pragma once

#include "model.hxx"
#include <ge211.hxx>

#include <string>

extern ge211::Color const light_color, dark_color;

class View
{
public:
    explicit View(Model const&);

    ge211::Font const sans30_{"sans.ttf", 30};
    ge211::Font const sans15_{"sans.ttf", 15};


    // You will probably want to add arguments here so that the
    // controller can communicate UI state (such as a mouse or
    // cursor position):
    void draw(ge211::Sprite_set&);

    ge211::Dimensions initial_window_dimensions() const;

    ge211::Position board_to_screen_(int) const;
    int screen_to_board(ge211 :: Position) const;

    void update_store_number_(int, int);

    void update_pocket_number_(int, int);


    //void on_mouse_down(ge211::Mouse_button, ge211::Position);
    //void move_piece_(ge211::Sprite_set&, Player, ge211::Position, int) const;

private:
    Model const& model_;


    ge211::Circle_sprite const pocket_{pocket_radius, light_color};
    ge211::Rectangle_sprite const source_{store_dims, light_color};
    ge211::Circle_sprite const piece_{piece_radius, dark_color};
    ge211::Text_sprite store_number_0 = ge211::Text_sprite("0",sans30_);
    ge211::Text_sprite store_number_7 = ge211::Text_sprite("0",sans30_);
    ge211::Text_sprite pocket_number_1 = ge211::Text_sprite{"4", sans15_};
    ge211::Text_sprite pocket_number_2 = ge211::Text_sprite{"4", sans15_};
    ge211::Text_sprite pocket_number_3 = ge211::Text_sprite{"4", sans15_};
    ge211::Text_sprite pocket_number_4 = ge211::Text_sprite{"4", sans15_};
    ge211::Text_sprite pocket_number_5 = ge211::Text_sprite{"4", sans15_};
    ge211::Text_sprite pocket_number_6 = ge211::Text_sprite{"4", sans15_};
    ge211::Text_sprite pocket_number_8 = ge211::Text_sprite{"4", sans15_};
    ge211::Text_sprite pocket_number_9 = ge211::Text_sprite{"4", sans15_};
    ge211::Text_sprite pocket_number_10 = ge211::Text_sprite{"4", sans15_};
    ge211::Text_sprite pocket_number_11 = ge211::Text_sprite{"4", sans15_};
    ge211::Text_sprite pocket_number_12 = ge211::Text_sprite{"4", sans15_};
    ge211::Text_sprite pocket_number_13 = ge211::Text_sprite{"4", sans15_};



};
