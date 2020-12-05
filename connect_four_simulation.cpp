
//****************************************************************************************
// Contributors: Tara Rao-Pandit & Devanshi Paliwal 
//
// C/C++ Arrays and Vectors, String Manipulation, Modular Design
// Purpose: A program that will allow two users to play 4x4 Tic-Tac-Toe
// November 6, 2020
//***********************************************************************

/* TESTING SCENARIOS:
* 1. Horizontal Winner (Player X or O gets a point)
* 2. Vertical Winner (Player X or O gets a point)
* 3. Both Diagonal Winner (Player X or O gets a point)
* 4. Tie Game (No one receives a point, and instead 1 tied game is shown)
* 5. Continuous Games where X and O win multiple times (both players were given the adequate number of wins, and ties were tallied if the game was a tie)
* The above 7 scenarios were tested as they seemed to be all the possible scenarios that could occur in a real game of tic-tac-toe
*The program was correct and verified by manually keeping score for each scenario

LIMITATIONS: There is no option for player X to become O, they must stick with who they are assigned at the beginning of the game
*/


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void X_turn(string(&game_array)[4][4]);
//Purpose: determines the moves made by player X and adds it to the game_array
//Inputs: game_array - an array to keep track of which positions have been taken, and which have yet to be filled
//Returns: Nothing

void O_turn(string(&game_array)[4][4]);
//Purpose: determines the moves made by player O and adds it to the game_array
//Inputs: game_array - an array to keep track of which positions have been taken, and which have yet to be filled
//Returns: Nothing
bool winner(string(&game_array)[4][4], bool& winner_row, bool& winner_column, bool& winner_diagonal1, bool& winner_diagonal2, int& column_number, int& row_number);
//Purpose: determines if there is a winner at any point in the game
//Inputs: game_array - an array to keep track of which positions have been taken, and which have yet to be filled
//          winner_row, winner_column, winner_diagonal1, winner_diagonal2 - bools to determine where the victory row is
//          column_number, row_number- ints to keep track of which row and column a player has won in
//Returns: true if a winner is found, false if not

void output_winner(bool& winner_row, bool& winner_column, bool& winner_diagonal1, bool& winner_diagonal2, string(&game_array)[4][4], int& column_number, int& row_number, int& X_score, int& O_score, int& O_loss, int& X_loss);
//Purpose: determines and outputs whether X or O has won
//Inputs: game_array - an array to keep track of which positions have been taken, and which have yet to be filled
//          winner_row, winner_column, winner_diagonal1, winner_diagonal2 - bools to determine where the victory row is
//          column_number, row_number- ints to keep track of which row and column a player has won in
//          X_loss, O_loss, X_score, O_score - ints to keep track of wins and losses for each player
//Returns: Nothing

void score(bool& x_winner, bool& o_winner, int& X_score, int& O_score, int& O_loss, int& X_loss);
//Purpose: determines and outputs the overall score of the game
//Inputs: x_winner and o_winner - bools to determine which player has won
//          X_score and O_score - ints to keep track of how many times each player has won
//          O_loss, X_loss - ints to keep track of how many games each player has lost
//Returns: Nothing

void output_game_array(string(&game_array)[4][4]);
//Purpose: outputs the game configuration with accurate spacing for visual effect
//Inputs: game_array - an array to keep track of which positions have been taken, and which have yet to be filled
//Returns: Nothing

bool play_again();
//Purpose: determines if players would like to play again or not
//Inputs: none
//Returns: True if the player chooses to play again, False if not

void play_game(string(&game_array)[4][4], int& turn_num, bool& winner_row, bool& winner_column, bool& winner_diagonal1, bool& winner_diagonal2, int& column_number, int& row_number, int& games_played, int& X_loss, int& O_loss, int& O_score, int& X_score, bool& o_winner, bool& x_winner, int& ties);
//Purpose: orders functions and ouputs to create coherent game structure
//Inputs: game_array - an array to keep track of which positions have been taken, and which have yet to be filled
//          winner_row, winner_column, winner_diagonal1, winner_diagonal2 - bools to determine where the victory row is
//          column_number, row_number- ints to keep track of which row and column a player has won in
//          turn num - int to determine which players turn it is, games_played - int to keep track of games played, ties - int to keep tally of tied rounds
//          X_loss, O_loss, X_score, O_score - ints to keep track of wins and losses for each player
//          x_winner, o_winner - bools to determine which player wins each round
//Returns: Nothing

int main()
{
    // declare and initialize variables
    int games_played = 1, turn_num = 1, X_score = 0, O_score = 0, ties = 0;
     bool winner_row = true, winner_column = true;
     bool winner_diagonal1 = false, winner_diagonal2 = false, x_winner = false, o_winner = false;
     int row_number = 0, column_number = 0;
     int O_loss = 0, X_loss = 0;
    string game_array[4][4] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16" };
    
    // start game
    play_game(game_array, turn_num, winner_row, winner_column, winner_diagonal1, winner_diagonal2, column_number, row_number, games_played, X_loss, O_loss, O_score, X_score, o_winner, x_winner, ties);
 
}

void X_turn(string(&game_array)[4][4])
{
    //output game configuration
    string X_move;  // declare and initialize string
    bool end_turn = false; // declare and initialize bool
    while (end_turn == false) {
    
    //ask player X to pick their spot
    cout << "Player X's Move. Enter Number: "; // ask player for number corresponding to move
    cin >> X_move;

    for (int rows = 0; rows < 4 && end_turn == false; rows++)
    {
        for (int columns = 0; columns < 4 && end_turn == false; columns++)
        {
            if (X_move == game_array[rows][columns]) // check if value inputed exists and is a possible move
            {
                game_array[rows][columns] = "X"; // swap number with X
                end_turn = true; // end turn
            }
        }
    }
    
    if (end_turn == false) // if number not found or move not possible, output invalid move and ask for another number
    {
        cout << "Invalid move. ";
}
}
}

void O_turn(string(&game_array)[4][4])
{
    string O_move;  //declare and initialize string

    // check whether number exists in array
    bool end_turn = false;  // declare and initialize bool
    while (end_turn == false)
    {
        cout << "Player O's Move. Enter number: "; // Ask player for number corresponding to move
        cin >> O_move;

        for (int row = 0; row < 4 && end_turn == false; row++) {
            for (int column = 0; column < 4 && end_turn == false; column++)
                if (game_array[row][column] == O_move) // check if value inputed exists and is a possible move
                {
                    game_array[row][column] = "O"; // swap number with O
                    end_turn = true;
                }
        }
        if (end_turn == false)
        {
            cout << "Invalid move. "; // if number not found or move not possible, output invalid move and ask for another number
        }
    }
}

//function 3 - check to see if a player has won (input = array)
//if statements across the array
bool winner(string(&game_array)[4][4], bool& winner_row, bool& winner_column, bool& winner_diagonal1, bool& winner_diagonal2, int& column_number, int& row_number)
{
    // declare and initialize variables
    winner_row = false;
    winner_column = false;
    winner_diagonal1 = false;
    winner_diagonal2 = false;
    row_number = 5;
    column_number = 5;

    //checking for vertical columns
    for (int i = 0; i < 4; i++) {
        if (game_array[0][i] == game_array[1][i] && game_array[1][i] == game_array[2][i] &&
            game_array[2][i] == game_array[3][i] && (game_array[0][i] == "O" || game_array[0][i] == "X")) {
            winner_column = true; // if any column is all X or all O set winner_column to true
            column_number = i;
        }
    }

    //checking for horizontal rows
    for (int i = 0; i < 4; i++) {
        if (game_array[i][0] == game_array[i][1] && game_array[i][1] == game_array[i][2] &&
            game_array[i][2] == game_array[i][3] && ((game_array[i][0] == "O" || game_array[i][0] == "X"))) {
            winner_row = true; // if any row is all X or all O set winner_row to true
            row_number = i;
        }
    }
    
    if (game_array[0][0] == game_array[1][1] && game_array[1][1] == game_array[2][2] && game_array[2][2] == game_array[3][3])
        winner_diagonal1 = true; // check the left diagonal

    if (game_array[0][3] == game_array[1][2] && game_array[1][2] == game_array[2][1] && game_array[2][1] == game_array[3][0])
        winner_diagonal2 = true; // check the right diagonal

    if (winner_row == true || winner_column == true || winner_diagonal1 == true || winner_diagonal2 == true) {
        return true; // return true if a player has won (all X or all O in a column, row or diagonal)
    }
    else return false;
}

void score(bool& x_winner, bool& o_winner, int& X_score, int& O_score, int& O_loss, int& X_loss)
{ // function to output winner
    if (x_winner == true)
    {
        cout << "Player X won the game! Congratulations!" << endl;
        X_score++; // increment X score by one
        O_loss++; // increment O loss by one
    }
    if (o_winner == true) {
        cout << "Player O won the game! Congratulations!" << endl;
        O_score++; // increment O score by one
        X_loss++; // increment X loss by one
    }
}

void output_winner(bool& winner_row, bool& winner_column, bool& winner_diagonal1, bool& winner_diagonal2, string(&game_array)[4][4], int& column_number, int& row_number, int& X_score, int& O_score, int& O_loss, int& X_loss)
{
    // declare and initialize bools for winners
    bool x_winner = false;
    bool o_winner = false;
    if (winner_row == true) { // if one of the rows is a winning row check whether X or O won
        if (game_array[row_number][0] == "X") // if string in winning row is X, X is winner otherwise O is winner
            x_winner = true;
        else o_winner = true;
    }

    if (winner_column == true) { // if one of the columns is a winning column check whether X or O won
        if (game_array[0][column_number] == "X") // if string in winning column is X, X is winner otherwise O is winner
            x_winner = true;
        else o_winner = true;
    }

    if (winner_diagonal1 == true) {
        if (game_array[0][0] == "X") // if X in diagonal1,  X is winner otherwise O is winner
            x_winner = true;
        else o_winner = true;
    }

    if (winner_diagonal2 == true) {
        if (game_array[3][0] == "X") // if X in diagonal2, X is winner otherwise O is winner
            x_winner = true;
        else o_winner = true;
    }

    score(x_winner, o_winner, X_score, O_score, O_loss, X_loss); // call score function
}


void output_game_array(string(&game_array)[4][4]) // function to output score
{
    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 4; column++) {
            int val = column;
            if (val < 3)
                cout << game_array[row][column] << setw(20); // add space between columns
            if (val == 3)
                cout << game_array[row][column] << endl << endl; // add space between rows
        }
    }
}

bool play_again(string(&game_array)[4][4])
{
    string answer;
    cout << "Would you like to play again? (Please enter 'Y' for yes and 'N' for no): "; // ask user if they want to keep playing
    cin >> answer;

    while (true)
    {
        if (answer == "Y" || answer == "y") {
        string reset_array[4][4] = { "1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16" }; // reset game board
            for (int row = 0; row < 4; row++) {
            for (int column = 0; column < 4; column++) {
                game_array[row][column] = reset_array[row][column];
            }
            }
            output_game_array(game_array);
            return true;
        }
        else if (answer == "N" || answer == "n")
            return false; // return false if they do not want to keep playing
        else
        {
            cout << "Please enter 'Y' for yes or 'N' for No: "; // ensure valid response from user
            cin >> answer;
        }
    }
}

void play_game (string(&game_array)[4][4], int& turn_num, bool& winner_row, bool& winner_column, bool& winner_diagonal1, bool& winner_diagonal2, int& column_number, int& row_number, int& games_played, int& X_loss, int& O_loss, int& O_score, int& X_score, bool& o_winner, bool& x_winner, int& ties) {
    //print the game configuration for players to see
    output_game_array(game_array);
     
     //game loop - checks if there is a winner or if it is a tie, ends after all 16 moves have been fulfilled
     do
     {
         for (int i = 0; i < 16; i++) // loop to check if there is a winner after every turn
         {
             if ((turn_num % 2 == 0))
                 O_turn(game_array);
             else
                 X_turn(game_array);

             turn_num++;
             output_game_array(game_array);

             //if winner determined output game statistics
             if (winner(game_array, winner_row, winner_column, winner_diagonal1, winner_diagonal2, column_number, row_number))
             {
                 output_winner(winner_row, winner_column, winner_diagonal1, winner_diagonal2, game_array, column_number, row_number, X_score, O_score, O_loss, X_loss);
                 cout << endl << "Here is the current score (Player X: Player O)" << endl; // output score
                 cout << "Wins - " << X_score << " : " << O_score << endl; // output wins
                 cout << "Losses - " << X_loss << " : " << O_loss << endl; // output losses
                 cout << "Ties - " << ties << endl; // output number of ties
                 break;
             }
         
                 if (i == 15 && !winner(game_array, winner_row, winner_column, winner_diagonal1, winner_diagonal2, column_number, row_number))
             { // if by the last turn there is no winner, declare a tie
                 ties++; // increment number of ties by 1
                 cout << endl << "Its a tie!" << endl << endl; // output that it's a tie and give an update on game statistics
                 cout << "Here is the current score (Player X: Player O)" << endl; // output score
                 cout << "Wins - " << X_score << " : " << O_score << endl; // output wins
                 cout << "Losses - " << X_loss << " : " << O_loss << endl; // output losses
                 cout << "Ties - " << ties << endl; // output number of ties
             }
             
     }
     }
         while (play_again(game_array));
    
    games_played = X_score + O_score + ties;
    // when game ends output final score and other game statistics
    cout << endl << "Thanks for playing! Here is the final score (Player X: Player O)" << endl;
    cout << "Wins - " << X_score << " : " << O_score << endl; // output final score
    cout << "Losses - " << X_loss << " : " << O_loss << endl; // output wins
    cout << "Ties - " << ties << endl;  // output losses
    cout << "Games Played - " << games_played << endl; // output number of games played
}
