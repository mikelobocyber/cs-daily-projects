/**
 * @file 3.9.cpp
 * @brief ISBN-10 lab
 * @author Miguel Angel Sevilla Ruiz
 * @date 26 February 2026
 *
 * This program repeatedly prompts the user to enter the first 9 digits of an ISBN-10 number, calculates the checksum digit, and displays the complete ISBN-10 number. The user can choose to enter another ISBN or exit the program.
 * The checksum digit is calculated using the formula:
 * checksum = (d1 * 10 + d2 * 9 + d3 * 8 + d4 * 7 + d5 * 6 + d6 * 5 + d7 * 4 + d8 * 3 + d9 * 2) % 11
 * If the checksum is 10, it is represented as 'X' in the ISBN-10 format.
 */

#include <iostream> // for input and output
#include <iomanip> // for setw and setfill
using namespace std; // for convenience

void runIsbnProgram() // function to run the ISBN program
{
    long long isbn9; // variable to store the first 9 digits of the ISBN
    long long temp; // variable to store a temporary copy of the ISBN for calculations
    int digit; // variable to store each digit of the ISBN during calculations
    int sum; // variable to store the sum of the weighted digits for checksum calculation
    int checksum; // variable to store the calculated checksum digit
    int weight; // variable to store the weight for each digit during checksum calculation
    char choice; // variable to store the user's choice to continue or exit the program

    choice = 'y'; // initialize choice to 'y' to enter the loop

    while (choice == 'y' || choice == 'Y') // loop to allow the user to enter multiple ISBNs
    {
        cout << "Enter the first 9 digits of an ISBN as an integer: "; // prompt the user to enter the first 9 digits of the ISBN
        cin >> isbn9; // read the input from the user

        while (isbn9 < 0 || isbn9 > 999999999) //range check to ensure the input is a valid 9-digit number
        {
            cout << "Invalid input. Enter a value from 0 to 999999999: "; // prompt the user to enter a valid 9-digit number if the input is out of range
            cin >> isbn9; // read the input again from the user
        }

        temp = isbn9; // copy the input to a temporary variable for calculations
        sum = 0; // initialize sum to 0 before starting the checksum calculation

        for (weight = 9; weight >= 1; weight--) // loop to calculate the weighted sum of the digits for checksum calculation
        {
            digit = temp % 10; // extract the last digit of the temporary variable
            sum = sum + digit * weight; // add the weighted digit to the sum
            temp = temp / 10; // remove the last digit from the temporary variable for the next iteration
        }

        checksum = sum % 11; // calculate the checksum digit using the modulus operator

        cout << "The ISBN-10 number is "; // display the complete ISBN-10 number
        cout << setw(9) << setfill('0') << isbn9; // display the first 9 digits of the ISBN, making sure to pad with zeros if necessary

        if (checksum == 10) // if the checksum is 10, display 'X' as the checksum digit
        {
            cout << "X" << endl; // display 'X' for checksum digit if it is 10
        }
        else // if the checksum is not 10, display the checksum digit as a number
        {
            cout << checksum << endl; // display the checksum digit as a number if it is not 10
        }

        cout << "Do you want to enter another ISBN? (y/n): "; // prompt the user to decide whether to enter another ISBN or exit the program and read their choice
        cin >> choice; // read the user's choice to continue or exit the program
        //the loop continues if the user enters y otherwise it exits the loop and the program ends
    }
}
