# greedy-robot

### Program Description
A robot is positioned on an integral point in a two-dimensional coordinate grid (xr, yr). There is
a treasure that has been placed at a point in the same grid at (xt, yt). All x’s and y’s will be
integral values. The robot can move up (North), down (South), left (West), or right (East).
Commands can be given to the robot to move one position in one of the four direction. That is,
“E” moves a robot one slot East (to the right) so if the robot was on position (3, 4), it would now
be on (4, 4). The command N would move the robot one position north so a robot at position
(4, 4) would be at (4, 5).


### Input 
An input of 1 3 -2 4 2 corresponds to the robot starting at position (1, 3) and
needing to get to position (-2, 4) with the constraints that one can only move 2 steps in one
direction before having to shift to a new position.


### Output
For the input 1 2 3 5 2 which corresponds to (1,2) -> (3,5), the output should be:

% GreedyRobot 1 2 3 5 2
NNENE
NNEEN
NENNE
NENEN
NEENN
ENNEN
ENENN
Number of paths: 7
