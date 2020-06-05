#include "model.hxx"

using namespace ge211;

Model::Model(int width, int height)
        : board_({width, height})
{
    std::vector<Pocket> pockets;
    {
            for (int i = 0; i <= 13; i = i + 1) {
                if (i == 7 || i == 0) {
                    pockets.push_back(Pocket{i, 0});
                } else {
                    pockets.push_back(Pocket{i, 4});
                }
            }
    }
    pockets_ = pockets;
}

Rectangle Model::board() const
{
    return board_.all_positions();
}

ge211::Dimensions Model::get_dims() const{
    return board_.dimensions();
}

void Model::change_player(){
    if(turn_ == Player::computer) {
        turn_ = Player::player;
        return;
    }
    if(turn_ == Player::player) {
        turn_ = Player::computer;
        return;
    }
}

bool Model::half_empty(){
    int sum = 0;
    if(pockets_[1].pieces == 0 && pockets_[2].pieces == 0 &&
            pockets_[3].pieces == 0 && pockets_[11].pieces == 0 &&
            pockets_[12].pieces == 0 && pockets_[13].pieces == 0){
        return true;
    }
    if(pockets_[4].pieces == 0 && pockets_[5].pieces == 0 &&
       pockets_[6].pieces == 0 && pockets_[8].pieces == 0 &&
       pockets_[9].pieces == 0 && pockets_[10].pieces == 0){
        return true;
    }
    return false;
}

void Model::update_pocket(int pock){
    int pock_num = pock;
    if(pockets_[pock].pieces == 0) return;
    if(!is_valid_pocket(pock)) return;

    int last_;
    int last_num;
    int init = pockets_[pock].pieces;

    pockets_[pock].pieces = 0;
    for (int i = init; i > 0; i = i - 1) {
        if(i == 1) {
            last_ = pock_num + 1;
            if(last_ == 14) last_ = 0;
            std::cout<<last_;
            last_num = pockets_[last_].pieces;
        }
        if (turn_ == Player::computer && pock_num + 1 == 0){
            pock_num = pock_num + 1;
        }
        if (turn_ == Player::player && pock_num + 1 == 7){
            pock_num = pock_num + 1;
        }
        if (pock_num == 13) {
        pockets_[0].pieces = pockets_[0].pieces + 1;
        pock_num = 0;
        }
        else {
            pockets_[pock_num + 1].pieces = pockets_[pock_num + 1].pieces + 1;
            pock_num = pock_num + 1;
        }
    }

    if(is_valid_pocket(last_) && last_num == 0){
        int other = get_oppsite_pocket(last_);
        if (turn_ == Player::player){
            pockets_[0].pieces = pockets_[0].pieces + 1 + pockets_[other].pieces;
        }
        if (turn_ == Player::computer){
            pockets_[7].pieces = pockets_[7].pieces + 1 + pockets_[other].pieces;
        }
        pockets_[other].pieces = 0;
        pockets_[last_].pieces = 0;
    }

    if (turn_ == Player::player && last_ != 0)
        change_player();
    else if (turn_ == Player::computer && last_ != 7)
        change_player();

    if(half_empty()){
        turn_ = Player::neither;
        if (pockets_[0].pieces > pockets_[7].pieces)
            winner_ = Player::player;
        else
            winner_ = Player::computer;
    }

}

bool Model::is_valid_pocket(int pock){
    if (turn_ == Player::player && (pock == 1||pock == 2||pock == 3||
                                    pock == 11|| pock == 12||pock == 13)){
        return true;
    }
    if (turn_ == Player::computer && (pock == 6||pock == 5||pock == 4||
                                    pock == 8|| pock == 9||pock == 10)){
        return true;
    } else {
        return false;
    }
}

int Model::get_oppsite_pocket(int pocket){
    if(pocket == 1)
        return 13;
    if(pocket == 2)
        return 12;
    if(pocket == 3)
        return 11;
    if(pocket == 4)
        return 10;
    if(pocket == 5)
        return 9;
    if(pocket == 6)
        return 8;
    if(pocket == 8)
        return 6;
    if(pocket == 9)
        return 5;
    if(pocket == 10)
        return 4;
    if(pocket == 11)
        return 3;
    if(pocket == 12)
        return 2;
    if(pocket == 13)
        return 1;
}