#pragma once

#include <ge211.hxx>

//
// Model constants:
//

const int piece_radius;
const ge211::Dimensions pocket_dims;
const ge211::Dimensions store_dims;

//
// Model classes:
//

struct Pocket
{
    // Number of pieces in the pocket
    int pieces;

    // Whether the pocket is empty
    bool empty;
};

enum class Player
{
    first, computer, neither
};

//Returns the other player
Player other_player(Player);

//The whole state of the game.
class Model
{
    //
    // PRIVATE DATA MEMBERS
    //

    // The center of each piece
    ge211::Position piece_;

    //The pockets
    std::vector<Pocket> pockets_;


public:
    //
    // PUBLIC FUNCTION
    //

    // Returns the number of piece in a store box.
    int get_store;

    // Puts a piece in a pocket
    void place_piece(int pocket_num);

    // Returns whose turn it is, or Player::neither for game over.
    Player turn() const { return turn_; };

    //Returns the winning player
    Player winner() const { return winner_; };

    // returns whether the game is over.
    bool game_is_finsihed() const;

    // Contains the twelve pockets
    std::vector<Pocket> const& get_pockets() const;

    //Updates the model status
    void change_player();

    // Returns if half the board is empty
    bool half_empty();

    // The current turn
    Player turn_   = Player::first;

    // The winning player
    Player winner_ = Player::neither;

private:
    //
    // POSSIBLE HELPER FUNCTIONS
    //

    // Updates the number of pieces in a pocket
    void update_pocket();

    // Updates the store box
    void update_store_box();

    // Takes pieces from opposite pocket if last piece placed in empty
    // pocket and puts them in the player's store
    void take_for_store();

    // Test access
    friend struct Test_access;
};
