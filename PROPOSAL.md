# Proposal: Mancala

## Synopsis

## Elements

Our game will have three elements:

- 48 circular pieces 
- The board is made of two stationary rows of six circular pockets and two 
stationary "store boxes" on the far left and right of the screen for each 
player's pieces 

## Goal
The player's goal is to collect the more pieces than the computer at the end of 
the game.

## Game play
The game will stat with no pieces in the store boxes and 4 pieces
 in each of the six pockets. The player then chooses one pocket on their side of 
 the board and deposits all of the pieces in that pocket one at a time in other pockets in a counter-clockwise direction until they run 
 out of pieces. If they encounter their own store, they place a piece in their 
 store, but if they encounter the computer's store they skip it. If they last 
 piece the player or computer puts is in their store, then they take another 
 turn, and if the last piece they put is in an empty pocket, they take that 
 piece and any pieces from the opposite pocket for their own store. The game 
 ends if all six pockets on one side of the board are empty. If it is the 
 computer's side that is empty, all of the piece on the player's side go to the
 player's store. If not, then the remaining pieces go the the computer's store. 

## Functional requirements

1. Board constructed correctly with two row of six pockets and two store boxes 
on either side.

2. The player selects a pocket by clicking on it.

3. The player moves the pieces to another pocket by clicking on the pocket.

4. if the player does not click on a pocket, nothing happens. 

5. The player cannot move the pieces to a pocket if it is not in the 
counter-clockwise direction. 

6. The player cannot put pieces in the computer's store and the computer cannot
put pieces in the players store. 

7. The player's store is treated as one of their pockets and the computer's 
store is treated as one of their pockets. 

8. Pieces cannot be removed from a store. 

9. If a player places their last piece in an empty pocket, that piece and any 
pieces from the opposite pocket are move to their store.

10. If a play places their last piece in their own store, they take another
turn.

11. The computer always makes the best move.

12. If one side of the board is empty, the game ends and the winner is 
determined by counting the number of pieces in each player's store. 


## Open questions

-How can we ensure that the computer is always making the best move?

-Is a tie possible? What should happen in this case?

-How do we indicate which pocket the computer selected and show their moves 
effectively?
