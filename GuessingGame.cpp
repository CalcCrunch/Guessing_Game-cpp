#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

/*
Title: Guessing Game in C++
Author: Nathan Singiri
Resource: https://medium.com/geekculture/how-to-build-a-guessing-game-with-c-6a79b6375446
*/


// Global variables
string s = "";
int user_guess = 0;
const int guess_limit = 3;
int num_guesses = 0;
bool guessInRange = true;

// Forward declarations
int getUserInput();
void playGame();

// Execution entry-point
int main()
{
    playGame();
    cout << "Thanks for playing!" << endl;
    return 0;
}

// Main implementation of Guessing Game
void playGame() {
    srand(time(0));
    // initialize secret number
    int secret_number = 1 + rand() % 10;
    while (s != "0" && num_guesses < guess_limit) {
        int guess = getUserInput();

        if (guess == 0) {
            cout << "You have quit the game." << endl;
            break;
        } else if (guess == secret_number) {
            cout << "You got it! You are amazing!!" << endl;
            break;
        } else if (guessInRange && guess < secret_number) {
            cout << "Nope, guess is too low!" << endl;
        } else if (guessInRange && guess > secret_number) {
            cout << "Nope, guess is too high!" << endl;
        }

        ++num_guesses;
    }
    if (num_guesses == guess_limit) {
        cout << "You are all out of guesses, the secret number was " << secret_number << "!" << endl;
    }
}

// Getting user input and validating it
int getUserInput() {
    try {
        cout << "---------------------------------------" << endl;
        cout << "Guess a number, 1 - 10, or 0 to quit. You've got " << (guess_limit - num_guesses) << " guesses left: " << endl;
        cin >> s;
        user_guess = stoi(s);

        if (user_guess > 10 || user_guess < 0) {
            cout << "Out of range." << endl;
            guessInRange = false;
        } else {
            cout << "You guessed " << user_guess << "." << endl;
            guessInRange = true;
        }
    }
    catch (invalid_argument const &e) {
        cout << "Bad input: invalid_argument thrown" << endl;
    }
    catch (out_of_range const &e) {
        cout << "Integer overflow" << endl;
    }
    return user_guess;
}

