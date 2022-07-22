#include <bits/stdc++.h>
using namespace std;

// Size of the board
#define SIDE 3

string PLAYER1, PLAYER2;

class game
{
private:
    // 3*3 Tic-Tac-Toe board
    char board[SIDE][SIDE];
    int moves[SIDE * SIDE];

public:
    // Show the current board status
    void showBoard()
    {
        printf("\n\n");
        printf("\t\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
        printf("\t\t\t------------\n");
        printf("\t\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
        printf("\t\t\t------------\n");
        printf("\t\t\t %c | %c | %c \n\n", board[2][0], board[2][1], board[2][2]);
    }

    // Show the instructions
    void showInstructions()
    {
        printf("\t\t\t Tic-Tac-Toe\n\n");
        printf("Choose a cell numbered from 1 to 9 as below and play\n\n");
        printf("\t\t\t 1 | 2 | 3 \n");
        printf("\t\t\t------------\n");
        printf("\t\t\t 4 | 5 | 6 \n");
        printf("\t\t\t------------\n");
        printf("\t\t\t 7 | 8 | 9 \n\n");
        printf("\n\n");
    }

    // Initialise the game
    void initialise()
    {
        // Initiate the random number generator so that the same configuration doesn't arises
        srand(time(NULL));

        // board is empty
        for (int i = 0; i < SIDE; i++)
        {
            for (int j = 0; j < SIDE; j++)
                board[i][j] = ' ';
        }

        // Filling the moves with numbers
        for (int i = 0; i < SIDE * SIDE; i++)
            moves[i] = i;

        // randomise the moves
        random_shuffle(moves, moves + SIDE * SIDE);
    }

    // Declare winner of the game
    void declareWinner(string whoseTurn)
    {
        if (whoseTurn == PLAYER1)
            cout << PLAYER1 << " has won\n";
        else
            cout << PLAYER1 << " has won\n";
    }

    // Returns true if any of the row is crossed with the same player's move
    bool rowCrossed()
    {
        for (int i = 0; i < SIDE; i++)
        {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
                return true;
        }
        return false;
    }

    // Returns true if any of the column is crossed with the same player's move
    bool columnCrossed()
    {
        for (int i = 0; i < SIDE; i++)
        {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
                return true;
        }
        return false;
    }

    // Returns true if any of the diagonal is crossed with the same player's move
    bool diagonalCrossed()
    {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
            return true;

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
            return true;

        return false;
    }

    // Returns true if the game is over else it returns a false
    bool gameOver()
    {
        return (rowCrossed() || columnCrossed() || diagonalCrossed());
    }

    // Play Tic-Tac-Toe
    void playTicTacToe(string whoseTurn)
    {

        // Initialise the game
        initialise();

        // Show instructions
        showInstructions();

        int moveIndex = 0;
        int r, c;

        // Keep playing till the game is over or it is a draw
        while (gameOver() == false && moveIndex != SIDE * SIDE)
        {
            if (whoseTurn == PLAYER1)
            {

            // Label for player1 wrong choice of row and column
            player1:
                // Input the desired row and column by player 1 to insert X
                cout << PLAYER1 << " enter the respective row and column to insert X :";
                cin >> r >> c;

                if (r <= 3 && c <= 3)
                {
                    // row and column should be empty
                    if (board[r - 1][c - 1] == ' ')
                        board[r - 1][c - 1] = 'X';
                    // If input is on already filled position
                    else
                    {
                        cout << "Positon already filled!!! :\n";
                        goto player1;
                    }
                }

                // If input is not valid
                else
                {
                    cout << "\nInput is not valid please enter right one\n";
                    goto player1;
                }
                showBoard();
                moveIndex++;
                whoseTurn = PLAYER2;
            }
            else if (whoseTurn == PLAYER2)
            {

            // Label for player2 wrong choice of row and column
            player2:

                // Input the desired row and column by player 2 to insert O
                cout << PLAYER2 << " Enter the respective row and column to insert O :";
                cin >> r >> c;
                if (r <= 3 && c <= 3)
                {
                    // row and column should be empty
                    if (board[r - 1][c - 1] == ' ')
                        board[r - 1][c - 1] = 'O';

                    // If input is on already filled position
                    else
                    {
                        cout << "Positon already filled!!! :\n";
                        goto player2;
                    }
                }
                // If input is not valid
                else
                {
                    cout << "\nInput is not valid please enter right one\n";
                    goto player2;
                }
                showBoard();
                moveIndex++;
                whoseTurn = PLAYER1;
            }
        }

        // If the game has drawn
        if (gameOver() == false && moveIndex == SIDE * SIDE)
            printf("It's a draw\n");
        else
        {
            // Toggling the user to declare the actual winner
            if (whoseTurn == PLAYER1)
                whoseTurn = PLAYER2;
            else if (whoseTurn == PLAYER2)
                whoseTurn = PLAYER1;
            declareWinner(whoseTurn);
        }
    }
};

int main()
{
    // Take the name of players
    cout << "Enter name of first Player: ";
    cin >> PLAYER1;

    cout << "Enter name of Second Player: ";
    cin >> PLAYER2;

    // Use current time as seed for random generator
    srand(time(0));

    // If random numbers are generated with rand() without first calling srand(), your program will create the same sequence of numbers each time it runs.

    // Lets do toss
    int toss = rand() % 2;

    game g1;
    // play the game
    if (toss == 1)
    {
        cout << PLAYER1 << " win the toss" << endl;
        g1.playTicTacToe(PLAYER1);
    }
    else
    {
        cout << PLAYER2 << " win the toss" << endl;
        g1.playTicTacToe(PLAYER2);
    }
    return (0);
}