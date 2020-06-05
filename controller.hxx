#pragma once

#include "model.hxx"
#include "view.hxx"

class Controller : public ge211::Abstract_game
{
public:
    Controller(int width, int height);
    ge211::Position mouse_ = {0,0};

protected:

    void draw(ge211::Sprite_set&) override;
    ge211::Dimensions initial_window_dimensions() const override;
    void on_mouse_down(ge211::Mouse_button, ge211::Position);
    void on_mouse_move(ge211::Position);

private:
    Model            model_;
    View             view_;

};