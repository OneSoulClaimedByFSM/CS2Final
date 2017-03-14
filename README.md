<<<<<<< HEAD
Caltech CS2 Assignment 9: Othello

See [assignment9_part1.html](http://htmlpreview.github.io/?https://github.com/caltechcs2/othello/blob/master/assignment9_part1.html) and [assignment9_part2.html](http://htmlpreview.github.io/?https://github.com/caltechcs2/othello/blob/master/assignment9_part2.html)
=======
# CS2Final
Final project for CS2

PLAYERNAME=flying spaghetti monster

>>>>>>> 01a5504ff8456857727ce24a1f1cae9d9ded507f

-------------------------RESPONSIBILITIES--------------------------

EMILY PAN:

I was responsible for heuristic functions and the first portion of
Part 1 (i.e. the not minimax part).

HANWEN ZHANG:

I wrote the minimax function and updated it to utilize alpha-beta
pruning. I also helped debug when Emily started faceplanting on the
floor.

-------------------------------LOG---------------------------------

Heuristics-wise, we used a combination of weighted spaces, mobility, and frontier
discs to calculate a total score for each branch of the mini-max function.  

Weighted spaces: corners were the most heavily weighted at 100 pts, while the rest
                 was determined with the help of an online resource.  Generally,
                 edges were considered favorable, while the inner corner was
                 the weighted the least.

Mobility:        summing of possible moves for our side, divided by the
                 sum of possible moves total.  This was weighted slightly higher
                 than the space scores.

Frontier:        summing of all empty adjacent spaces of our pieces, divided
                 by the total number of adjacent spaces of both sides.  This
                 was weighted the lowest.

If the game has ended, the score becomes the difference in the number of coins
between each side.

Algorithm wise, we recursively explores the decision tree to a depth of four. We
choose moves using the minimax algorithm enhanced with alpha-beta pruning.
