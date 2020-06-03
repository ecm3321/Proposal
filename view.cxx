#include "view.hxx"

using ge211::Color;

using Dimensions = ge211::Dimensions;
using Position   = ge211::Position;
using Color      = ge211::Color;
using Sprite_set = ge211::Sprite_set;

 Color const dark_color {0,0,0};
 Color const light_color {255,255,255};


View::View(Model const& model)
        : model_(model)
{ }

void View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(source_, {10,20});
    set.add_sprite(store_number_, {10,20});
    set.add_sprite(source_, {initial_window_dimensions().width-store_dims
    .width - 10, 20});
    set.add_sprite(store_number_, {initial_window_dimensions().width- store_dims
            .width - 10,20});

    for (int i = 110; i < initial_window_dimensions().width - store_dims.width; i
    = i + 100){
        for (int j = 20; j < initial_window_dimensions().height; j = j + 130){
            set.add_sprite(pocket_, {i,j});
            //set.add_sprite(pocket_number_, {i + 10,j + 10});
            set.add_sprite(piece_, {i,j});
        }
    }
}

Dimensions View::initial_window_dimensions() const
{
    return {800, 250};
}