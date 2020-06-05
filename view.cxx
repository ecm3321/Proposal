#include "view.hxx"

using ge211::Color;

using Dimensions = ge211::Dimensions;
using Position   = ge211::Position;
using Color      = ge211::Color;
using Sprite_set = ge211::Sprite_set;

 Color const dark_color {3, 252, 123};
 Color const light_color {3, 161, 252};


View::View(Model& model)
        : model_(model)
{ }

void View::draw(ge211::Sprite_set& set, ge211::Position mouse)
{
    //add stores, labels and store numbers
    set.add_sprite(source_, {10,20});
    set.add_sprite(source_, {initial_window_dimensions().width-store_dims
    .width - 10, 20});
    set.add_sprite(computer_1, {13, 200}, 3);
    set.add_sprite(player_1, {initial_window_dimensions()
                                        .width-store_dims.width,
                                                initial_window_dimensions()
                                                .height - 50},3);
    set.add_sprite(store_number_7, {12,10});
    set.add_sprite(store_number_0, {initial_window_dimensions()
                                               .width-store_dims.width - 8,10},
                                                       5);

    //add pockets, pocket numbers, and pieces
    int num = 6;
    while (num < 14){
    for (int j = 20; j < initial_window_dimensions().height; j = j + 130){
        for (int i = 110; i < initial_window_dimensions().width - store_dims
                .width -40 ; i = i + 100) {
            set.add_sprite(pocket_, {i, j});
            if (num == 1)
                set.add_sprite(pocket_number_1, {i + 25, j + 20}, 11);
            else if (num == 2)
                set.add_sprite(pocket_number_2, {i + 25, j + 20}, 11);
            else if (num == 3)
                set.add_sprite(pocket_number_3, {i + 25, j + 20}, 11);
            else if (num == 4)
                set.add_sprite(pocket_number_4, {i + 25, j + 20}, 11);
            else if (num == 5)
                set.add_sprite(pocket_number_5, {i + 25, j + 20}, 11);
            else if (num == 6)
                set.add_sprite(pocket_number_6, {i + 25, j + 20}, 11);
            else if (num == 8)
                set.add_sprite(pocket_number_8, {i + 25, j + 20}, 11);
            else if (num == 9)
                set.add_sprite(pocket_number_9, {i + 25, j + 20}, 11);
            else if (num == 10)
                set.add_sprite(pocket_number_10, {i + 25, j + 20}, 11);
            else if (num == 11)
                set.add_sprite(pocket_number_11, {i + 25, j + 20}, 11);
            else if (num == 12)
                set.add_sprite(pocket_number_12, {i + 25, j + 20}, 11);
            else if (num == 13)
                set.add_sprite(pocket_number_13, {i + 25, j + 20}, 11);
            if (model_.pockets_[screen_to_board({i, j})].pieces != 0) {
                set.add_sprite(piece_, {i + 20, j + 20}, 5);
            }
            if(num >= 8) num = num + 1;
            if (num <= 6) num = num - 1;
            if (num == 0) num = 8;
        }
        }
    }

    //Mouse shows whose turn
    if (model_.turn() == Player::player){
        set.add_sprite(player_1, mouse, 20);
    } else if (model_.turn() == Player::computer){
        set.add_sprite(computer_1, mouse, 20);
    }
}

Dimensions View::initial_window_dimensions() const
{
    return {800, 250};
}

ge211::Position View::board_to_screen_(int pocket) const
{
    if(pocket == 1)
        return {20,110};
    if(pocket == 2)
        return {20,210};
    if(pocket == 3)
        return {20,310};
    if(pocket == 4)
        return {20,410};
    if(pocket == 5)
        return {20,510};
    if(pocket == 6)
        return {20,610};
    if(pocket == 8)
        return {150,110};
    if(pocket == 9)
        return {150,210};
    if(pocket == 10)
        return {150,310};
    if(pocket == 11)
        return {150,410};
    if(pocket == 12)
        return {150,510};
    if(pocket == 13)
        return {150,610};

}
int View::screen_to_board(ge211 :: Position screen_posn) const
{
    if (screen_posn.y < 20 + 2 * pocket_radius && screen_posn.y > 20){
        if (screen_posn.x > 110 && screen_posn.x < 110 + 2 * pocket_radius)
            return 6;
        if (screen_posn.x > 210 && screen_posn.x < 210 + 2 * pocket_radius)
            return 5;
        if (screen_posn.x > 310 && screen_posn.x < 310 + 2 * pocket_radius)
            return 4;
        if (screen_posn.x > 410 && screen_posn.x < 410 + 2 * pocket_radius)
            return 3;
        if (screen_posn.x > 510 && screen_posn.x < 510 + 2 * pocket_radius)
            return 2;
        if (screen_posn.x > 610 && screen_posn.x < 610 + 2 * pocket_radius)
            return 1;
    }
    else if (screen_posn.y > 150 && screen_posn.y < 150 + 2 * pocket_radius){
        if (screen_posn.x > 110 && screen_posn.x < 110 + 2 * pocket_radius)
            return 8;
        if (screen_posn.x > 210 && screen_posn.x < 210 + 2 * pocket_radius)
            return 9;
        if (screen_posn.x > 310 && screen_posn.x < 310 + 2 * pocket_radius)
            return 10;
        if (screen_posn.x > 410 && screen_posn.x < 410 + 2 * pocket_radius)
            return 11;
        if (screen_posn.x > 510 && screen_posn.x < 510 + 2 * pocket_radius)
            return 12;
        if (screen_posn.x > 610 && screen_posn.x < 610 + 2 * pocket_radius)
            return 13;
    }
    else{
        return 20;
    }
}

void View::update_store_number_(int store, int val)
{
    if (store == 0)
        store_number_0.reconfigure(ge211::Text_sprite::Builder(sans30_)
        <<std::to_string(val));
    if (store == 7)
        store_number_7.reconfigure(ge211::Text_sprite::Builder(sans30_)
        <<std::to_string(val));
}

void View::update_pocket_number_(int pocket, int val)
{

    if(pocket == 1)
        pocket_number_1.reconfigure(ge211::Text_sprite::Builder(sans15_) <<std::to_string(val));
    if(pocket == 2)
        pocket_number_2.reconfigure(ge211::Text_sprite::Builder(sans15_) <<std::to_string(val));
    if(pocket == 3)
        pocket_number_3.reconfigure(ge211::Text_sprite::Builder(sans15_) <<std::to_string(val));
    if(pocket == 4)
        pocket_number_4.reconfigure(ge211::Text_sprite::Builder(sans15_) <<std::to_string(val));
    if(pocket == 5)
        pocket_number_5.reconfigure(ge211::Text_sprite::Builder(sans15_) <<std::to_string(val));
    if(pocket == 6)
        pocket_number_6.reconfigure(ge211::Text_sprite::Builder(sans15_) <<std::to_string(val));
    if(pocket == 8)
        pocket_number_8.reconfigure(ge211::Text_sprite::Builder(sans15_) <<std::to_string(val));
    if(pocket == 9)
        pocket_number_9.reconfigure(ge211::Text_sprite::Builder(sans15_) <<std::to_string(val));
    if(pocket == 10)
        pocket_number_10.reconfigure(ge211::Text_sprite::Builder(sans15_) <<std::to_string(val));
    if(pocket == 11)
        pocket_number_11.reconfigure(ge211::Text_sprite::Builder(sans15_) <<std::to_string(val));
    if(pocket == 12)
        pocket_number_12.reconfigure(ge211::Text_sprite::Builder(sans15_) <<std::to_string(val));
    if(pocket == 13)
        pocket_number_13.reconfigure(ge211::Text_sprite::Builder(sans15_) <<std::to_string(val));

}