#pragma once

#include <ge211.hxx>
#include "board.hxx"
#include <vector>

//
// Model constants:
//

const int piece_radius = 15;
const int pocket_radius = 40;
const ge211::Dimensions store_dims = {80,210};

//
// Model classes:
//


struct Pocket
{
    //Pocket number
    int num;

    // Number of pieces in the pocket
    int pieces;
};

enum class Player
{
    player, computer, neither
};

//The whole state of the game.
class Model
{
public:

    std::vector<Pocket> pockets_;

    //
    // PUBLIC FUNCTION
    //

    // Constructs a model with the given width and height.
    Model(int width, int height);

    // Returns a rectangle containing all the positions of the board.
    // This can be used to iterate over the positions.
    ge211::Rectangle board() const;

    // Returns the dimensions of the board
    ge211::Dimensions get_dims() const;

    // Returns whose turn it is, or Player::neither for game over.
    Player turn() const { return turn_; };

    //Returns the winning player
    Player winner() const { return winner_; };

    // returns whether the game is over.
    bool game_is_finsihed() const
    { return turn() == Player::neither; }

    //Updates the model status
    void change_player();

    // Returns if half the board is empty
    bool half_empty();

    // Updates the number of pieces in a pocket
    void update_pocket(int);

private:

    // The current turn
    Player turn_ = Player::player;

    // The winning player
    Player winner_ = Player::neither;
    Board board_;

    //
    // POSSIBLE HELPER FUNCTIONS
    //

    bool is_valid_pocket(int);

    int get_oppsite_pocket(int);

    // Test access
    friend struct Test_access;
};