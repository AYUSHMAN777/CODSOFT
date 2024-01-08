#include <iostream>
#include <cstdlib>
#include <ctime>


int main() {
    srand(time(0)); // Seed the random number generator with current time
    int GeneratedNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int Guess = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "Try to Guess the number between 1 and 100.\n";

    while (Guess != GeneratedNumber) {
        std::cout << "Enter your Guess: ";
        std::cin >> Guess;

        if (Guess == GeneratedNumber) {
            std::cout << "Congratulations! You've Guessed the correct number.\n";
            break;
        } else if (Guess < GeneratedNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Too high! Try again.\n";
        }
    }

    return 0;
}

