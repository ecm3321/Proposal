#include "controller.hxx"

Controller::Controller(int width, int height)
        : model_(width, height)
        , view_(model_)
{ }

void Controller::draw(ge211::Sprite_set& sprites)
{
    view_.draw(sprites);

}

ge211::Dimensions Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

void Controller::on_mouse_down(ge211::Mouse_button btn, ge211::Position
screen_posn)
{
    if (model_.turn() == Player::neither) return;
    if (btn != ge211::Mouse_button::left) return;

    int select_pocket = view_.screen_to_board(screen_posn);
    if(model_.pockets_[select_pocket].pieces != 0)
        model_.update_pocket(model_.pockets_[select_pocket]);
    for (int i = 0; i < 14; i = i + 1) {
        view_.update_pocket_number_(model_.pockets_[i].num,
                                    model_.pockets_[i].pieces);
    }
}