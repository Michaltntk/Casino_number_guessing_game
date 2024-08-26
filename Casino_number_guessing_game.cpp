#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstdio>

using namespace std;

string answering();

int main()
{
    int guess_number; // number guessed by player
    int computer_number; // number guessed by computer
    string player_answer; // Player answer to if keep playing game still or quiting
    cout << "Hello welcome to our casino. Come and play number guessing game by Michaltntk\n";
    do // Loop created so player can play again and quit
    {
        cout << "Write your number: ";
        cin >> guess_number; // inserting player number
        //Checking if input is number or not
        if(!cin) // or if(cin.fail())
        {
            do
            {
            // user didn't input a number
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            // next, request user reinput
            cout << "You must write a number: ";
            cin >> guess_number; // inserting player number
            }
            while(!cin);
        }
        srand(time(NULL)); // Initialiazing randomness 
        computer_number = rand()%10+1; // assaining random number from 1 to 10 
        cout << "Number that has been choosen by computer: " << computer_number << endl;
        if (guess_number==computer_number)
        {
            cout << "Congratulations. You won\n";
            player_answer = answering();
        }
        else
        {
            cout << "Oh dang it\n";
            player_answer = answering();
        } 
    }
    while (player_answer=="Yes" || player_answer=="Y");
    getchar();
}

string answering()
{
    string player_answer;
    cout << "Do you wanna play again?\n";
        cin >> player_answer;
        do
        {
            if (player_answer == "Yes" || player_answer == "Y" || player_answer == "No" || player_answer == "N")
                {
                    if (player_answer == "Yes" || player_answer == "Y")
                    {
                    cout << "Let's go gambling\n";
                    break;
                    }
                    else
                    {
                    cout << "U could have hit it big";
                    break;
                    }
                }
            else
            {
                cout << "Please write answer in type of Yes or Y for confirmation, and No or N for decline: ";
                cin >> player_answer;
            }
        }
        while(player_answer != "Yes" || player_answer != "Y" || player_answer != "No" || player_answer != "N");
        return player_answer;
}