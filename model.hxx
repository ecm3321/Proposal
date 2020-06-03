#pragma once

#include <ge211.hxx>
#include "board.hxx"
#include <vector>

//
// Model constants:
//

const int piece_radius;
const int pocket_radius;
const ge211::Dimensions store_dims;

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

struct Piece
{
    // Which player the piece belongs to if any
    Player player;

    //number of the pocket of the piece, 0 if in store
    int pocket;
};

struct Store
{
    // Which player the store belongs to
    const Player player;

    //The center of store
    ge211::Position center;

    // Number of pieces in store
    int num;
};

//Returns the other player
Player other_player(Player);

//The whole state of the game.
class Model
{
public:
    // The stores
    std::vector<Store> stores_;

    // The pieces
    std::vector<Piece> pieces_;

    //The pockets
    std::vector<Pocket> pockets_;

    //
    // PUBLIC FUNCTION
    //

    // Constructs a model with the given width and height.
    Model(int width, int height);

    // Returns a rectangle containing all the positions of the board.
    // This can be used to iterate over the positions.
    ge211::Rectangle board() const;

    // Puts a piece in a pocket
    void place_piece(int pocket_num);

    // Returns the dimensions of the board
    ge211::Dimensions get_dims() const;

    // Returns whose turn it is, or Player::neither for game over.
    Player turn() const { return turn_; };

    //Returns the winning player
    Player winner() const { return winner_; };

    // returns whether the game is over.
    bool game_is_finsihed() const
    { return turn() == Player::neither; }

    // Contains the twelve pockets
    std::vector<Pocket>& get_pockets() const;

    // Contains the 48 pieces
    std::vector<Piece>& get_pieces() const;

    //Updates the model status
    void change_player();

    // Returns if half the board is empty
    bool half_empty();

private:
    // The current turn
    Player turn_ = Player::player;

    // The winning player
    Player winner_ = Player::neither;
    Board board_;

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