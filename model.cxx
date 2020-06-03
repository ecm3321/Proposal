#include "model.hxx"

using namespace ge211;

Model::Model(int width, int height)
        : board_({width, height})
{
    std::vector<Store> pockets;
    {
        for (int i = 0; i < 13; ++i) {
            if
            pockets.push_back({})
        }

    }
    pockets_ = pockets;
}

Rectangle Model::board() const
{
    return board_.all_positions();
}

void place_piece(int pocket_num){
    pockets_[pocket_num].pieces =  pockets_[pocket_num].pieces + 1;
    if (pocket_num != 7 && pocket_num != 14)
        pieces_[pocket_num].pocket = pocket_num;
}

void Model::play_move(Pocket p)
{
    int pocket_num= p.pieces;
    for(int i=0; i<pocket_num; i++)
    {
        pockets_[(p.location+i)%14]+=1;
    }
}

