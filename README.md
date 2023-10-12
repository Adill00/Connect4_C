Connect4  fun to play. Rules are simple: 
    • It is a two-player board game
    • Players choose a color 
    • Then take turns dropping colored discs into a seven-column, six-row grid. 
    • The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of same color discs , while preventing opponent from doing the same. 

-------------------------------------------------------------------------

Rules of the game :
    • Choose the first player. The player who starts the first game will be the second player in the second game.
    • Each player takes turns dropping one of their discs into one of the slots at the top of the grid.
    • Play continues until a player has a continuous alignment of four discs of his color. Alignment can be vertical, horizontal or diagonal.
    • To clear the grid, push the retaining bar at the bottom of it and the discs fall. You can now start the next part.

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

1: Preparing for the game
The game "Connect 4" is played on a vertical grid of six rows and seven columns with 21 red discs and 21 yellow discs. Define the types needed to represent the game grid.

2: Clear the grid
To start each game, you must first empty the grid of discs it contains. Write a subprogram that does this.

3: Show the grid
Write a subprogram that displays the contents of the grid;
    • red discs will be represented by (*)
    • yellow discs by the lowercase letter o

4: Deciding if a move is possible
Write a subprogram that indicates whether it is possible to play in a given column.

5: Drop a disc
Write a subprogram that calculates the new state of grid when a disc is dropped above a given column.

6: Count the aligned disc
Write a subprogram that indicates what is the length of the longest alignment of a given disc (identified by its column number and row number). Alignments should be checked in all directions (horizontal, vertical or diagonal).
This subprogram will then be used to determine the end of a game (alignment ≥ 4) or to help the computer choose which column to play

7: Recommend a column to play in
Write a subprogram which, given a grid, offers a column in which to play. The column number will be chosen at random.

8: Improve advice
To improve the advice, we add an additional constraint: advise the column that allows the longest alignment.
Note: If a winning move exists, the advice column will lead to victory.

9: Play a game
Write a program that lets a human player play against the computer. The human player is considered to have the yellow chips and begins the game.
