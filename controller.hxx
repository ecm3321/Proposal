#pragma once

#include "model.hxx"
#include "view.hxx"

// The main game class for Reversi.
class Controller : public ge211::Abstract_game
{
public:
    Controller(int width, int height);

protected:
    //void on_mouse_down(ge211::Mouse_button, ge211::Position) override;
   // void on_mouse_move(ge211::Position) override ;

    // These three delegate to the view:
    void draw(ge211::Sprite_set&) override;
    ge211::Dimensions initial_window_dimensions() const override;

private:
    Model            model_;
    View             view_;
};