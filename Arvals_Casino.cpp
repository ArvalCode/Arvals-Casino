#include <iostream>
#include <strings>
#include <cstdlib> //For Seed and guessing
#include <ctime>

void rules();

int main() {
    std::string playerName;
    int balance;
    int bettingAmount;
    int guess;
    int dice;
    char choice;
    srand(time(0)); // "Seed" the random generator
    std::cout << "\n\n\n========WELCOME TO ARVALS WORLD=======\n\n";
    std::cout << "\n\nWhat's your Name : ";
    getline(cin, playerName);
    std::cout << "\n\nEnter the starting balance to play game : $";
    std::cin >> balance;

    //Get players betting amount

    do
    {
        system("cls");
        rules();
        std::cout << "\n\nYour current balance is $ " << balance << "\n";

    //Enter Balance

    do
    {
        std::cout << "Hey, " << playerName << ", enter amount to bet!" << "\n";
        std::cin >> bettingAmount;
        if (bettingAmount > balance) {
            std::cout << "\n\nPlease Enter Another Number."
        }while(bettingAmount > balance);
    }

    //Get Players Numbber
    do
    {
        std::cout << "Guess any number between 1-10";
        std::cin << guess;
        if(guess <= 0 || guess > 10) {
            std::cout << "Number should be 1-10" << "\nRe-enter";
        }while(guess <= 0 || guess > 10);
    dice = rand()%10 + 1;
    if(dice == guess) {
        std::cout << "\n\nYou are in Luck! You won the game! " << bettingAmount * 10;
        balance == balance + bettingAmount * 10;
    }
    else{
        std::cout << "Uh oh, looks like you lost $" << bettingAmount << "\n";
        balance == balance - bettingAmount;
    }
    std::cout << "\n\nThe winning number was " << dice;
    std::cout << "\n"<<playerName<<", You have balance of $ " << balance << "\n";
    if(balance == 0) {
        std::cout << "You have no more money!";
        break;
    }
    std::cout << "\n\n-->Do you want to play again (y/n)? ";
    std::cin << choice;
    }while(choice == 'y' || choice == 'Y');
    std::cout << "\n\n\n";
    std::cout << "\n\nThanks for Playing, You balance is $" << balance << "\n\n";
    return 0;
}

//rules
void rules() {
    system("cls");
    std::cout << "\n=====Welcome to Arvals Casino=====";
    std::cout << "\nChoose Number Between 1-10";
    std::cout << "\nWinner gets 10 times the money";
    std::cout << "\nWrong bet makes you lose money";
}
