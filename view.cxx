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

void View::draw(ge211::Sprite_set& set, Model const& model)
{
    set.add_sprite(source_, {10,10});
    set.add_sprite(store_number_, {10,10}));
    set.add_sprite(source_, {10, model.get_dims().width});

    for (int i = store_dims.width; i < 6; i = i + store_dims.width/8){
        for (int j = store_dims.height; j < 2; j = j + store_dims.height/2){
            set.add_sprite(pocket_, {i + 10,j + 10});
            set.add_sprite(pocket_number_, {i + 10,j + 10});
            set.add_sprite(piece_, {i,j});
        }
    }
}