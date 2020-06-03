#include "model.hxx"

using namespace ge211;

Model::Model(int width, int height)
        : board_({width, height})
{
    std::vector<Pocket> pockets;
    {
        for (int i = 13; i > 0; --i) {
            if(i != 0 && i != 7) {
                pockets.push_back(Pocket{4,i});
            } else {
                i = i - 1;
            }
        }

    }
    pockets_ = pockets;

    std::vector<Store> stores;
    {
        stores.push_back({Player::player, 0});
        stores.push_back({Player::computer, 0});
    }
    stores_ = stores;

    std::vector<Piece> pieces;
    {
        for (int i = 13; i > 0; --i) {
            if(i != 0 && i != 7) {
                pieces.push_back(Piece{Player::neither,i});
                pieces.push_back(Piece{Player::neither,i});
                pieces.push_back(Piece{Player::neither,i});
                pieces.push_back(Piece{Player::neither,i});
            } else {
                i = i - 1;
            }
        }

    }
    pieces_ = pieces;

}

Rectangle Model::board() const
{
    return board_.all_positions();
}

void Model::place_piece(int pocket_num){
    if (pocket_num != 0 && pocket_num != 7) {
        pockets_[pocket_num].pieces = pockets_[pocket_num].pieces + 1;
        pieces_[pocket_num].pocket  = pocket_num;
    } else {
        if(turn_ == Player::computer)
            stores_[0].num = stores_[0].num + 1;
        else
            stores_[1].num = stores_[1].num + 1;
    }
}

ge211::Dimensions Model::get_dims() const{
    return board_.dimensions();
}

void Model::change_player(){
    if(turn_ == Player::computer)
        turn_ = Player::player;
    if(turn_ == Player::player)
        turn_ = Player::computer;
}

bool Model::half_empty(){
    int sum = 0;
    if(pockets_[1].pieces == 0 && pockets_[2].pieces == 0 &&
            pockets_[3].pieces == 0 && pockets_[10].pieces == 0 &&
            pockets_[11].pieces == 0 && pockets_[12].pieces == 0){
        return true;
    }
    if(pockets_[4].pieces == 0 && pockets_[5].pieces == 0 &&
       pockets_[6].pieces == 0 && pockets_[8].pieces == 0 &&
       pockets_[9].pieces == 0 && pockets_[10].pieces == 0){
        return true;
    }
    return false;
}

void Model::update_pocket(){
    //TODO
}

void Model::update_store_box(){
    //TODO
}

void Model::take_for_store(){
    //TODO
}