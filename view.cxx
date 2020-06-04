#include "view.hxx"

using ge211::Color;

using Dimensions = ge211::Dimensions;
using Position   = ge211::Position;
using Color      = ge211::Color;
using Sprite_set = ge211::Sprite_set;

 Color const dark_color {252, 3, 123};
 Color const light_color {3, 161, 252};


View::View(Model const& model)
        : model_(model)
{ }

void View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(source_, {10,20});
    set.add_sprite(source_, {initial_window_dimensions().width-store_dims
    .width - 10, 20});
    set.add_sprite(store_number_, {12,10});
    set.add_sprite(store_number_, {initial_window_dimensions()
                                               .width-store_dims.width - 8,10},
                                                       5);

    for (int i = 110; i < initial_window_dimensions().width - store_dims
    .width -40 ; i = i + 100){
        for (int j = 20; j < initial_window_dimensions().height; j = j + 130){
            set.add_sprite(pocket_, {i,j});
            set.add_sprite(piece_, {i + 20, j + 20}, 5);
            set.add_sprite(pocket_number_, {i + 25, j + 20}, 11);
        }
    }
}

Dimensions View::initial_window_dimensions() const
{
    return {800, 250};
}

void View::update_store_number_(int val)
{
    ge211::Text_sprite::Builder builder(sans30_);
    int now = cached_val_stor + val;

    builder.message(std::to_string(now));
    store_number_.reconfigure(builder);
    cached_val_stor = now;
}

void View::update_pocket_number_(int val)
{
    ge211::Text_sprite::Builder builder(sans15_);
    int now = cached_val_pock + val;

    builder.message(std::to_string(now));
    pocket_number_.reconfigure(builder);
    cached_val_pock = now;
}