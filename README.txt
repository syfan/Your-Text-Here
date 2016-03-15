Ty Limpasuvan

I was on a solo team called Your Text Here.  The random move AI worked successfully.  When any
further modifications were made, it stopped working and I was unable to fix it.  The first step to
getting the AI to be tournament ready was to get it to beat simple player.  I believe my logic 
would have worked if the program hadn't stopped working.  It was to find the possible moves
and get the resultant score from each one and return the move that brought the best score.  This 
greedy solution would defeat simple player since it played randomly.  After that, a minimax
algorithm is needed in order to have the greatest gain and smallest loss with each turn.  After,
I would have used iterative deepening to avoid the problem of having incomplete searches under
given time constraints.  Combining the time awareness with the minimax algorithm gives a good
AI for Othello.