/**
 * @file main.cpp
 * @brief Menu for Assignment 4
 * @author Miguel Angel Sevilla Ruiz
 * @date 26 February 2026
 *
 * This program lets the user choose between:
 * 1. 3.9 – ISBN
 * 2. 4.22.8 – Game of Nim
 */

#include <iostream> // for input and output
using namespace std; // for convenience

// function prototypes 
void runIsbnProgram(); // function prototype for the ISBN program, which will be defined in 3.9.cpp
void runNimProgram(); // function prototype for the Nim program, which will be defined in 4.22.8.cpp

int main() // main function to run the menu and allow the user to choose which program to run
{
    int choice; // variable to store the user's choice for which program to run, 1 for ISBN and 2 for Nim

    cout << "Select a program to run:" << endl; // display a menu for the user to choose which program to run
    cout << "1 - ISBN-10 Checksum" << endl; // display the option for the ISBN program in the menu
    cout << "2 - Game of Nim" << endl; // display the option for the Nim program in the menu
    cout << "Enter your choice: "; // prompt the user to enter their choice for which program to run
    cin >> choice; // read the user's input for their choice of program to run

    cout << endl; // print a blank line for better readability after the user enters their choice

    if (choice == 1) // if the user chooses 1, run the ISBN program by calling the function defined in 3.9.cpp
    {
        runIsbnProgram(); // call the function to run the ISBN program, which will allow the user to enter the first 9 digits of an ISBN-10 number, calculate the checksum digit, and display the complete ISBN-10 number, and also allow the user to enter multiple ISBNs if they choose to continue
    }
    else if (choice == 2) // if the user chooses 2, run the Nim program by calling the function defined in 4.22.8.cpp
    {
        runNimProgram(); // call the function to run the Nim program, which will let a human play Nim against the computer, with the computer randomly choosing to play in either stupid mode (taking a random valid number of marbles each turn) or smart mode (playing strategically to try to win), and also randomly deciding who goes first, to make the game more interesting and unpredictable each time it is played
    }
    else // if the user enters an invalid choice that is not 1 or 2, display an error message to indicate that the choice is invalid
    {
        cout << "Invalid choice." << endl; // display an error message to indicate that the user's choice is invalid if they enter a number that is not 1 or 2, prompting them to run the program again and enter a valid choice
    }

    return 0; // return 0 to indicate that the program ended successfully
}
