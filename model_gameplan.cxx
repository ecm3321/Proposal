#include "model.hxx"

using namespace ge211;

Model::Model(int width, int height)
        : board_({width, height})
{
    std::vector<Pocket> pockets;
    {
        for (int i = 13; i >= 0; --i) {
            pockets.push_back(Pocket{4,i});
        }

    }
    pockets_ = pockets; //why are you doing this?


}

Rectangle Model::board() const
{
    return board_.all_positions();
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

/*
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
*/
/*
Pocket& Model::num_to_pocket(int n)
{
    for(int i=0; i<14; i++)
    {
        if (pockets_[i].num == n)
        {
            return pockets_[i];
        }
    }
}
*/
/*
void Model::update_pocket(Pocket p)
{
    //Pocket& p =num_to_pocket(pocket_num);
    int pocket_num= p.pieces;
    for(int i=0; i<pocket_num; i++)
    {
        int temp= (p.num + i)%14;
        if(turn_==Player::player) {
            if(temp !=0) {
                pockets_[temp].pieces += 1;
            }
        } else {
            if(temp !=7 || (temp==7 && i==pocket_num)) {
                pockets_[temp].pieces += 1;
            }


        }
    }
}
 */

void Model::update_pocket(int index)
{
    Pocket p = pockets_[index];
    int last_stone_location
    for (circular loop)
    {
        distributes stones
        stores location of last stone

    }
    if(alone_in_pocket(last_stone_location))
    {
        int adj= get_adjacent(last_stone_location);
        if((on_playerside(last_stone_location) && turn_==player)
        || on_playerside(last_stone_location) && turn_==player)
        {
            add_to_store(adj);
        }
    }
    if(!in_own_store(last_stone_location))
    {
        advance_turn();
    }
if (player_wins() || computer_wins())
{
    turn_==Player::neither;
}
}

bool in_own_store(int stone_location)
{
    return ((is players turn and stone is in pocket 1)||(compters turn and stone in pocket 7)
}

void Model::add_to_store(int pocket_location) {
if (turn_==player && on_playerside(pocket_location)){
    adds stones to pocket 0
    removes stones from p
} else{
    adds stones to pocket 7
    removes stones from p
}
}

bool Model::on_playerside(pocket_locatoin)
{

returns true if the pocket is located on the players side
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
