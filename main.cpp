#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

// Function to clear the console screen
void clearScreen() {
    system("clear || cls");
}

// Rock Paper Scissors function with score tracking
string rps(string choice, int& playerScore, int& cpuScore, int& tieScore) {
    // Convert choice to lowercase
    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    int cpuchoice = rand() % 3 + 1;
    int numChoice;

    if (choice == "rock") {
        numChoice = 1;
    } else if (choice == "paper") {
        numChoice = 2;
    } else if (choice == "scissors") {
        numChoice = 3;
    } else {
        numChoice = 0;
    }

    // Display computer's choice
    cout << "Computer chose: ";
    switch (cpuchoice) {
    case 1:
        cout << "Rock";
        break;
    case 2:
        cout << "Paper";
        break;
    case 3:
        cout << "Scissors";
        break;
    }

    cout << endl;

    switch (numChoice) {
    case 1:
        if (cpuchoice == 1) {
            tieScore++;
            return "Tie";
        } else if (cpuchoice == 2) {
            cpuScore++;
            return "CPU Wins";
        } else if (cpuchoice == 3) {
            playerScore++;
            return "Player Wins";
        }
        break;

    case 2:
        if (cpuchoice == 1) {
            playerScore++;
            return "Player Wins";
        } else if (cpuchoice == 2) {
            tieScore++;
            return "Tie";
        } else if (cpuchoice == 3) {
            cpuScore++;
            return "CPU Wins";
        }
        break;

    case 3:
        if (cpuchoice == 1) {
            cpuScore++;
            return "CPU Wins";
        } else if (cpuchoice == 2) {
            playerScore++;
            return "Player Wins";
        } else if (cpuchoice == 3) {
            tieScore++;
            return "Tie";
        }
        break;

    default:
        break;
    }

    return "Error";
}

// Function for the game
void playGame() {
    // Seed the random number generator with the current time
    srand(time(0));  

    char playAgain;
    int playerScore = 0, cpuScore = 0, tieScore = 0;

    do {
        clearScreen(); 

        string playerChoice;
        cout << "Enter your choice (rock, paper, scissors): ";
        getline(cin, playerChoice);

        string result = rps(playerChoice, playerScore, cpuScore, tieScore);
        cout << "Result: " << result << endl;

        cout << "Score - Player: " << playerScore << " | CPU: " << cpuScore << " | Ties: " << tieScore << endl;

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        
         // Ignore the newline character in the input buffer
         cin.ignore(); 
    } while (playAgain == 'y' || playAgain == 'Y');
}

int main() {
    // Call the main game loop function
    playGame();  
    return 0;
}
