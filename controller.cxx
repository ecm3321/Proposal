#include "controller.hxx"

Controller::Controller(int width, int height)
        : model_(width, height)
        , view_(model_)
{ }

void Controller::draw(ge211::Sprite_set& sprites)
{
    view_.draw(sprites, mouse_);

    //Shows winner
    if (model_.half_empty() && model_.winner() == Player::player){
        sprites.add_sprite(player_2, {350, 100},30);
    }
    if (model_.half_empty() && model_.winner() == Player::computer) {
        sprites.add_sprite(computer_2, {350, 100},30);
    }

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
    if(select_pocket < 14 && model_.pockets_[select_pocket].pieces != 0) {
        model_.update_pocket(select_pocket);
    }

    for (int i = 1; i < 14; i = i + 1) {
        if (i == 7) i = 8;
        view_.update_pocket_number_(i,model_.pockets_[i].pieces);
    }
    view_.update_store_number_(0,model_.pockets_[0].pieces);
    view_.update_store_number_(7,model_.pockets_[7].pieces);

}

void Controller::on_mouse_move(ge211::Position screen_pos)
{
    mouse_ = screen_pos;
}