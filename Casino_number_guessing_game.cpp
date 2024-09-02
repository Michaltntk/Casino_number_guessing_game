#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstdio>

using namespace std;

string answering();

int main()
{
    int money = 200; // Money that player has
    int guess_number; // number guessed by player
    int computer_number; // number guessed by computer
    int choice;
    string player_answer; // Player answer to if keep playing game still or quiting
    srand(time(NULL)); // Initialiazing randomness
    cout << "Hello welcome to our casino. Come and play number guessing game by Michaltntk\n";
    do // Loop created so player can play again and quit
    {
        cout << "You have: " << money << "$\n";
        cout << "Please choose dificulty that you want: \n";
        cout << "1. Easy play for 1$ Win 10$ Numbers are between 1-10\n";
        cout << "2. Medium play for 10$ Win 100$ Numbers are between 1-20\n";
        cout << "3. Hard play for 100$ Win 1000$ Numbers are between 1-50\n";
        do
        {
            cin >> choice;
            switch (choice)
            {
                case 1:
                    computer_number = rand()%10+1; // assaining random number from 1 to 10
                    money -= 1;
                    break;
                case 2:
                    computer_number = rand()%20+1; // assaining random number from 1 to 20 
                    money -= 10;
                    break;
                case 3:
                    computer_number = rand()%50+1; // assaining random number from 1 to 50 
                    money -= 100;
                    break;
                default:
                    cout << "Please pick a correct option: \n";
                    break;
            }
            
        }
        while(choice != 1 && choice != 2 && choice != 3);
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
        
        cout << "Number that has been choosen by computer: " << computer_number << endl;
        if (guess_number==computer_number)
        {
            cout << "Congratulations. You won\n";
            switch (choice)
            {
            case 1:
                money += 10;
                break;
            case 2:
                money += 100;
                break;
            case 3:
                money += 1000;
                break;
            default:
                break;
            }
            player_answer = answering();
        }
        else
        {
            cout << "Oh dang it\n";
            if (money == 0)
            {
            cout << "You can't play anymore, you don't have any money left\n";
            break;
            }
            player_answer = answering();
        }
        
        
    }
    while (player_answer=="Yes" || player_answer=="Y");
    system("pause");
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
                    cout << "U could have hit it big\n";
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
