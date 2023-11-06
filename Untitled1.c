// A simple tic tac toe game in C programming

#include <stdio.h>
#include <stdlib.h>

// Define the board size and the symbols for the players
#define SIZE 3
#define X 'X'
#define O 'O'

// Declare a global 2D array for the board
char board[SIZE][SIZE];

// Function prototypes
void init_board(); // Initialize the board with empty spaces
void display_board(); // Display the board on the screen
void get_move(char player); // Get a valid move from the player
int check_win(char player); // Check if the player has won the game
int check_draw(); // Check if the game is a draw

// The main function
int main()
{
    char player = X; // The current player, X goes first
    int win = 0; // The win flag, 0 means no winner yet
    int draw = 0; // The draw flag, 0 means not a draw yet

    // Initialize and display the board
    init_board();
    display_board();

    // Loop until there is a winner or a draw
    while (!win && !draw)
    {
        // Get a valid move from the current player
        get_move(player);

        // Display the board after the move
        display_board();

        // Check if the current player has won the game
        win = check_win(player);

        // If not, check if the game is a draw
        if (!win)
        {
            draw = check_draw();
        }

        // Switch the player for the next turn
        if (player == X)
        {
            player = O;
        }
        else
        {
            player = X;
        }
    }

    // Display the final result
    if (win)
    {
        // The previous player is the winner
        if (player == X)
        {
            player = O;
        }
        else
        {
            player = X;
        }
        printf("Player %c wins!\n", player);
    }
    else
    {
        printf("It's a draw!\n");
    }

    return 0;
}

// Function to initialize the board with empty spaces
void init_board()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board on the screen
void display_board()
{
    printf("\n");

    // Print the column numbers
    printf("  ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", i + 1);
    }
    printf("\n");

    // Print the row numbers and the board cells
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c ", board[i][j]);
            if (j < SIZE - 1)
            {
                printf("| ");
            }
        }
        printf("\n");
        if (i < SIZE - 1)
        {
            // Print the horizontal line
            printf("  ");
            for (int j = 0; j < SIZE; j++)
            {
                printf("--");
                if (j < SIZE - 1)
                {
                    printf("+");
                }
            }
            printf("\n");
        }
    }

    printf("\n");
}

// Function to get a valid move from the player
void get_move(char player)
{
    int row, col; // The row and column of the move
    int valid = 0; // The validity flag, 0 means invalid

    // Loop until the player enters a valid move
    while (!valid)
    {
        // Prompt the player to enter the row and column
        printf("Player %c, enter your move (row, col): ", player);
        scanf("%d %d", &row, &col);

        // Adjust the row and column to the array index
        row--;
        col--;

        // Check if the row and column are within the board range
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE)
        {
            // Check if the board cell is empty
            if (board[row][col] == ' ')
            {
                // Place the player's symbol on the board
                board[row][col] = player;

                // Set the validity flag to 1
                valid = 1;
            }
            else
            {
                // The cell is already occupied
                printf("That cell is already taken.\n");
            }
        }
        else
        {
            // The row or column is out of the board range
            printf("Invalid move. Please enter a valid row and column.\n");
        }
    }
}

// Function to check if the player has won the game
int check_win(char player)
{
    int win = 0; // The win flag, 0 means no winner yet

    // Check the rows
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            win = 1;
            break;
        }
    }

    // Check the columns
    for (int i = 0; i < SIZE; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            win = 1;
            break;
        }
    }

    // Check the diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        win = 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        win = 1;
    }

    return win;
}

// Function to check if the game is a draw
int check_draw()
{
    int draw = 1; // The draw flag, 1 means a draw

    // Check if there is any empty cell on the board
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                // There is an empty cell, so not a draw
                draw = 0;
                break;
            }
        }
        if (!draw)
        {
            break;
        }
    }

    return draw;
}

