/**
 * @file 4.22.8.cpp
 * @brief Nim
 * @author Miguel Angel Sevilla Ruiz
 * @date 26 February 2026
 *
 * This program lets a human play Nim against the computer.
 * 
 */

#include <iostream> // for input and output
#include <cstdlib> // for rand and srand
#include <ctime> // for time to seed the random number generator
using namespace std; // for convenience

// draws the pile using O characters
void drawPile(int pile) // function to draw the pile of marbles, I thought it would be fun to visualize the pile as we play instead of just showing the number of marbles remaining
{
    cout << "Pile: "; // display the label for the pile

    for (int i = 0; i < pile; i++) // loop to draw the pile of marbles using 'O' characters, one for each marble remaining in the pile
    {
        cout << "O "; // display an 'O' character for each marble in the pile, followed by a space for better readability
    }

    cout << endl; // move to the next line after drawing the pile
}

void runNimProgram() // function to run the Nim game program
{
    int pile; // variable to store the number of marbles in the pile
    int maxTake; // variable to store the maximum number of marbles that can be taken in a turn, which is half of the current pile size
    int humanTake; // variable to store the number of marbles taken by the human player in their turn
    int computerTake; // variable to store the number of marbles taken by the computer player in its turn
    int turn; //    variable to store whose turn it is, 0 for human and 1 for computer
    int mode; // variable to store the computer's mode of play, 0 for stupid mode and 1 for smart mode
    int target; //  variable to store the target number of marbles the computer aims for in smart mode, which is one less than a power of 2 (1, 3, 7, 15, 31, 63) to try to force a win

    srand(time(0)); // seed the random number generator with the current time to ensure different random numbers each time the program is run

    pile = rand() % 91 + 10; // initialize the pile with a random number of marbles between 10 and 100 (inclusive) to make the game more interesting and unpredictable each time it is played
    turn = rand() % 2; // randomly decide who goes first, 0 for human and 1 for computer, to add an element of chance to the game
    mode = rand() % 2; // randomly decide the computer's mode of play, 0 for stupid mode where it takes a random valid number of marbles, and 1 for smart mode where it tries to play strategically to win, to add variety to the computer's behavior in the game

    cout << "Welcome to the Game of Nim!!!!" << endl; // display a welcome message to the user when the program starts
    cout << "The starting pile has " << pile << " marbles." << endl; // display the initial number of marbles in the pile to the user at the start of the game
    drawPile(pile); // call the function to draw the initial pile of marbles visually for the user at the start of the game

    if (turn == 0) // if the human player goes first, display a message to indicate that the human goes first
    {
        cout << "You go first." << endl; // display a message to indicate that the human goes first
    }
    else
    {
        cout << "The computer goes first." << endl; // display a message to indicate that the computer goes first
    }

    if (mode == 0) // if the computer is in stupid mode, display a message to indicate that the computer is playing in stupid mode
    {
        cout << "The computer is playing in stupid mode." << endl; // display a message to indicate that the computer is playing in stupid mode, where it will take a random valid number of marbles each turn without any strategic consideration
    }
    else // if the computer is in smart mode, display a message to indicate that the computer is playing in smart mode
    {
        cout << "The computer is playing in smart mode." << endl; // display a message to indicate that the computer is playing in smart mode, where it will try to play strategically to win by aiming for target numbers of marbles that are one less than a power of 2 (1, 3, 7, 15, 31, 63) to try to force the human player into a losing position
    }

    while (pile > 0) // main game loop that continues until there are no marbles left in the pile, at which point the game ends and a winner is declared based on who took the last marble
    {
        if (pile == 1) // if there is only 1 marble left in the pile, the player whose turn it is must take that last marble and loses the game, so we check for this condition to determine the winner and end the game
        {
            if (turn == 0) // if it is the human player's turn and there is only 1 marble left, the human must take that last marble and loses, so we display a message to indicate that the human loses and the computer wins
            {
                cout << "Only 1 marble remains." << endl; // display a message to indicate that there is only 1 marble left in the pile, which means the player whose turn it is must take it and lose the game
                drawPile(pile); // call the function to draw the pile, which will show that there is only 1 marble left visually for the user
                cout << "You must take the last marble and you lose." << endl; // display a message to indicate that the human player must
                cout << "The computer wins." << endl; // display a message to indicate that the computer wins since the human player took
            }
            else // if it is the computer player's turn and there is only 1 marble left, the computer must take that last marble and loses, so we display a message to indicate that the computer loses and the human wins
            {
                cout << "Only 1 marble remains." << endl; // display a message to indicate that there is only 1 marble left in the pile, which means the player whose turn it is must take it and lose the game
                drawPile(pile); // call the function to draw the pile, which will show that there is only 1 marble left visually for the user
                cout << "The computer must take the last marble and loses." << endl; // display a message to indicate that the computer player must take the last marble and loses
                cout << "The human wins." << endl; // display a message to indicate that the human wins since the computer player took the last marble and loses
            }

            break; // break out of the loop to end the game since there are no marbles left and a winner has been declared
        }

        maxTake = pile / 2; // calculate the maximum number of marbles that can be taken in a turn, which is half of the current pile size, to enforce the rules of the game where a player can take between 1 and half of the marbles in the pile on their turn

        if (turn == 0) // if it is the human player's turn, we prompt the user to enter how many marbles they want to take, ensuring that the input is valid and within the allowed range, and then update the pile and switch turns
        {
            cout << endl; // print a blank line for better readability between turns
            cout << "There are " << pile << " marbles in the pile." << endl; // display the current number of marbles in the pile to the user at the start of their turn
            drawPile(pile); // call the function to draw the current pile of marbles visually for the user at the start of their turn
            cout << "You may take between 1 and " << maxTake << " marbles." << endl; // display a message to inform the user of the valid range of marbles they can take on their turn based on the current pile size
            cout << "How many marbles will you take? "; // prompt the user to enter the number of marbles they want to take on their turn and read their input
            cin >> humanTake; // read the user's input for how many marbles they want to take on their turn

            while (humanTake < 1 || humanTake > maxTake) // input validation loop to ensure the user enters a valid number of marbles to take, which must be between 1 and the maximum allowed based on the current pile size
            {
                cout << "Invalid move. Enter a number between 1 and " << maxTake << ": "; // if the user enters an invalid number of marbles to take, display an error message and prompt them to enter a valid number again
                cin >> humanTake; // read the user's input again for how many marbles they want to take on their turn after an invalid entry
            }

            pile = pile - humanTake; // update the pile by subtracting the number of marbles taken by the human player from the current pile size
            cout << "You take " << humanTake << " marbles." << endl; // display a message to indicate how many marbles the human player took on their turn
            turn = 1; // switch turns to the computer player for the next iteration of the loop
        }
        else // if it is the computer player's turn, we determine how many marbles the computer will take based on its mode of play (stupid or smart), update the pile, and switch turns
        {
            cout << endl; // print a blank line for better readability between turns
            cout << "There are " << pile << " marbles in the pile." << endl; // display the current number of marbles in the pile to the user at the start of the computer's turn
            drawPile(pile); // call the function to draw the current pile of marbles visually for the user at the start of the computer's turn

            if (mode == 0) // if the computer is in stupid mode, it will take a random valid number of marbles between 1 and the maximum allowed based on the current pile size, without any strategic consideration
            {
                computerTake = rand() % maxTake + 1; // generate a random number of marbles for the computer to take in stupid mode, which is between 1 and the maximum allowed based on the current pile size, to simulate the computer making a non-strategic move
            }
            else // if the computer is in smart mode, it will try to play strategically to win by aiming for target numbers of marbles that are one less than a power of 2 (1, 3, 7, 15, 31, 63) to try to force the human player into a losing position, and if it cannot reach a target number, it will take a random valid number of marbles
            {
                if (pile > 63) // if the pile is greater than 63, the computer will aim for a target of 63 marbles to try to force the human player into a losing position
                {
                    target = 63; // set the target number of marbles for the computer to aim for in smart mode based on the current pile size, which is one less than a power of 2 (1, 3, 7, 15, 31, 63) to try to force the human player into a losing position
                }
                else if (pile > 31) // if the pile is greater than 31 but less than or equal to 63, the computer will aim for a target of 31 marbles to try to force the human player into a losing position
                {
                    target = 31; // set the target number of marbles for the computer to aim for in smart mode based on the current pile size, which is one less than a power of 2 (1, 3, 7, 15, 31, 63) to try to force the human player into a losing position
                }
                else if (pile > 15)
                {
                    target = 15; // set the target number of marbles for the computer to aim for in smart mode based on the current pile size, which is one less than a power of 2 (1, 3, 7, 15, 31, 63) to try to force the human player into a losing position
                }
                else if (pile > 7) // if the pile is greater than 7 but less than or equal to 15, the computer will aim for a target of 7 marbles to try to force the human player into a losing position
                {
                    target = 7; // set the target number of marbles for the computer to aim for in smart mode based on the current pile size, which is one less than a power of 2 (1, 3, 7, 15, 31, 63) to try to force the human player into
                }
                else if (pile > 3) // if the pile is greater than 3 but less than or equal to 7, the computer will aim for a target of 3 marbles to try to force the human player into a losing position
                {
                    target = 3; // set the target number of marbles for the computer to aim for in smart mode based on the current pile size, which is one less than a power of 2 (1, 3, 7, 15, 31, 63) to try to force the human player into
                }
                else // if the pile is greater than 1 but less than or equal to 3, the computer will aim for a target of 1 marble to try to force the human player into
                {
                    target = 1; // set the target number of marbles for the computer to aim for in smart mode based on the current pile size, which is one less than a power of 2 (1, 3, 7, 15, 31, 63) to try to force the human player into
                }

                computerTake = pile - target; // calculate the number of marbles the computer will take in smart mode by subtracting the target number of marbles from the current pile size, which is the strategic move to try to force the human player into a losing position

                if (computerTake < 1 || computerTake > maxTake) // if the calculated number of marbles for the computer to take in smart mode is not a valid move (less than 1 or greater than the maximum allowed based on the current pile size), then the computer will take a random valid number of marbles instead, to ensure that the computer always makes a valid move even if it cannot reach a target number
                {
                    computerTake = rand() % maxTake + 1; // generate a random number of marbles for the computer to take in smart mode if the calculated strategic move is not valid, which is between 1 and the maximum allowed based on the current pile size, to simulate the computer making a non-strategic move when it cannot reach a target number
                }
            }

            pile = pile - computerTake; // update the pile by subtracting the number of marbles taken by the computer player from the current pile size
            cout << "The computer takes " << computerTake << " marbles." << endl; // display a message to indicate how many marbles the computer player took on its turn
            turn = 0; // switch turns back to the human player for the next iteration of the loop
        }
    }
}