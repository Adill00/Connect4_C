#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for cell states
#define EMPTY 0
#define RED 1
#define YELLOW 2

// Define the grid
int grid[6][7]; // 6 rows, 7 columns

// Part 2: Clear the grid
void clearGrid() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            grid[i][j] = EMPTY;
        }
    }
}

// Part 3: Show the grid
void showGrid() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (grid[i][j] == EMPTY) {
                printf(".");
            } else if (grid[i][j] == RED) {
                printf("*");
            } else if (grid[i][j] == YELLOW) {
                printf("o");
            }
            printf(" "); // Separate cells
        }
        printf("\n");
    }
}

// Part 4: Deciding if a move is possible
int isMovePossible(int column) {
    return (grid[0][column] == EMPTY);
}

// Part 5: Drop a disc
void dropDisc(int column, int player) {
    int row;
    for (row = 5; row >= 0; row--) {
        if (grid[row][column] == EMPTY) {
            grid[row][column] = player;
            break;
        }
    }
}

// Part 6: Count the aligned discs
int checkAlignment(int column, int row, int player) {
    int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    int maxLength = 0;
    
    for (int d = 0; d < 4; d++) {
        int dx = directions[d][0];
        int dy = directions[d][1];
        int length = 1;

        // Check in one direction
        for (int step = 1; step < 4; step++) {
            int newRow = row + step * dy;
            int newColumn = column + step * dx;

            if (newRow >= 0 && newRow < 6 && newColumn >= 0 && newColumn < 7 &&
                grid[newRow][newColumn] == player) {
                length++;
            } else {
                break;
            }
        }

        // Check in the opposite direction
        for (int step = 1; step < 4; step++) {
            int newRow = row - step * dy;
            int newColumn = column - step * dx;

            if (newRow >= 0 && newRow < 6 && newColumn >= 0 && newColumn < 7 &&
                grid[newRow][newColumn] == player) {
                length++;
            } else {
                break;
            }
        }

        if (length > maxLength) {
            maxLength = length;
        }
    }

    return maxLength;
}

// Part 7: Recommend a column to play in
int recommendRandomColumn() {
    return rand() % 7;
}

// Part 8: Improve advice
int recommendBestColumn(int player) {
    int bestColumn = -1;
    int maxLength = -1;

    for (int col = 0; col < 7; col++) {
        if (isMovePossible(col)) {
            int row;
            for (row = 5; row >= 0; row--) {
                if (grid[row][col] == EMPTY) {
                    break;
                }
            }

            int length = checkAlignment(col, row, player);
            if (length > maxLength) {
                maxLength = length;
                bestColumn = col;
            }
        }
    }

    return bestColumn;
}

int main() {
    srand(time(NULL));
    
    clearGrid();
    showGrid();
    
    int currentPlayer = YELLOW;
    int winner = 0;
    
    while (1) {
        int column;

        if (currentPlayer == YELLOW) {
            do {
                printf("Enter the column (0-6) to drop a yellow disc: ");
                scanf("%d", &column);
            } while (column < 0 || column > 6 || !isMovePossible(column));
        } else {
            column = recommendBestColumn(RED);
        }

        dropDisc(column, currentPlayer);
        showGrid();

        if (checkAlignment(column, 5, currentPlayer) >= 4) {
            winner = currentPlayer;
            break;
        }

        currentPlayer = (currentPlayer == YELLOW) ? RED : YELLOW;
    }

    if (winner == YELLOW) {
        printf("Congratulations! Yellow player wins!\n");
    } else if (winner == RED) {
        printf("The computer wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}
