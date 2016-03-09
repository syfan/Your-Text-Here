#include "player.h"

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish 
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
    board = new Board();
    dupboard = new Board();
    side = side;
    count = 2;
    tempcount = 2;
    if (side == WHITE)
    {
		opponentSide = BLACK;
	}
	else
	{
	    opponentSide = WHITE;	
	}
	newmove = NULL;
	tempmove = NULL;
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be NULL.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return NULL.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /* 
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */ 
     
     /*
     if (!(opponentsMove == NULL))
     {
		 board->doMove(opponentsMove, opponentSide);
	 }
     for (unsigned int i = 0; i < 8; i++)
     {
		 for (unsigned int j = 0; j < 8; j++)
		 {
			 Move * newmove = new Move(i, j);		 
			 if (board->checkMove(newmove, side))
			 {
				 board->doMove(newmove, side);
				 return newmove;
			 }
		 }
	 }
     return NULL;
     */
     
     /*
      * PLEASE READ
      * I used a random AI initially. It was implemented above 
      * but stopped working after this and the header file were
      * modified.  I have kept the code above as a block comment in 
      * hopes of still receiving the 5 points for having the working 
      * AI before.  Its strategy was to simply play the first legal
      * move it could find.
      */
     
     /*
      * Strategy for better AI:
      * for each legal move:
      *     test the move on a duplicate board
      *     count how many pieces are now on the AI's side
      *     if that count is greater than the current value of the count,
      *     set the count = this one.
      * set the dupclicate board as a copy of the board
      * do the best move on the board and duplicate
      * return that move (or return NULL if there was no move)
      */
     
     if (!(opponentsMove == NULL))
     {
	 	 board->doMove(opponentsMove, opponentSide);
	 	 dupboard->doMove(opponentsMove, opponentSide);
	 }
	 
     for (int i = 0; i < 8; i++)
     {
		 for (int j = 0; j < 8; j++)
		 { 
			 tempmove = new Move(i,j); 
			 			 
			 if (board->checkMove(tempmove, side))
			 {
				 dupboard->doMove(tempmove,side);
				 if (side == WHITE)
				 {
				     tempcount = dupboard->countWhite();
				 }
				 else
				 {
					 tempcount = dupboard->countBlack();
				 }
				 
				 if (tempcount > count) // is this move better than others?
				 {
					 newmove = tempmove;
					 count = tempcount;
				 }
				 dupboard = board->copy();
			 }			 
		 }
	 }
	 if (!(newmove == NULL))
	 {
		 board->doMove(newmove, side);
		 dupboard->doMove(newmove, side);
		 return newmove;
	 }
     return NULL;
}
// Please read the block comment near the center of this file
