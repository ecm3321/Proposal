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

/*
void Model::play_move(Pocket p)
{
    int pocket_num= p.pieces;
    for(int i=0; i<pocket_num; i++)
    {
        pockets_[(p.location+i)%14]+=1;
    }
}
*/

//formerly play move
void Model::distribute_tokens(Pocket p, Player player)
{
    int pocket_num= p.pieces;
    for(int i=0; i<=pocket_num; i++)
    {
        int temp= (p.location + i)%14;
        if(player==Player::first) {
            if(temp !=0 || (temp==0 && i==pocket_num)) {
                pockets_[temp].pieces += 1;
            }
        } else {
            if(temp !=7 || (temp==7 && i==pocket_num)) {
                pockets_[temp].pieces += 1;
            }


        }
    }
}

bool player_wins()
{
 int total=0;
 for(int i=1; i<=3; i++)
 {
    total = total + pockets_.pieces;
 }
 for(int j=11; j<=13; j++)
 {
     total = total + pockets_.pieces;
 }
 return total == 0;
 //winner_=Player::computer;
}

bool computer_wins()
{
    int total=0;
    for(int i=4; i<=6; i++)
    {
        total = total + pockets_.pieces;
    }
    for(int j=8; j<=10; j++)
    {
        total = total + pockets_.pieces;
    }
    return total == 0;
    //winner_=Player::computer;
}



