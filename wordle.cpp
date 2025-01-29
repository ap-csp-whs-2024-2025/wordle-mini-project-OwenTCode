
#include "listhelpers.hpp"

#include <cstdlib>   
#include <ctime>     
#include <iostream>  
#include <string>
#include <vector>   

std::vector<int> createSecret() {
    //randcode here :3 
    std::vector<int> randomNumbers;
    srand(time(0));
    for (int i = 0; i < 4; i++){ 
        int random_num = rand() % 10;    
        randomNumbers.push_back(random_num);
    }
    
    return randomNumbers;    
}

std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess) {
   
    std::vector<std::string> hint;
    for (int i = 0; i < 4; i++){
        if (secret[i] == guess[i]){
            hint.push_back("O");
        }
        else{
            hint.push_back("X");
        }
    }
    return hint;   
}

bool winGame(std::vector<int> secret, std::vector<int> guess) {
  
    if (secret == guess) {
        return true;
    }
    else {
        return false;
    }
    
}

int main()
{

    
    std::vector<int> secret_code = createSecret();
    std::vector<int> user_guess = {};
    std::vector<std::string> hint = {};    
    
    int secret_code_length = 4;
    int num_guesses = 0;

    std::cout << "Welcome to Numdle!\n";
    
    while (!winGame(secret_code, user_guess))    
    {
        user_guess.clear();
        std::cout << "\nEnter your guess: ";
        hint = {};    
        for (int counter = 0; counter < secret_code_length; counter = counter + 1)
        {
            int input;
            std::cin >> input;
            user_guess.push_back(input);
           
        }
        
        hint = getHint(secret_code, user_guess);
        display(hint);
        num_guesses = num_guesses + 1;
        
    }

    std::cout << "Congrats! You guessed the code! It took you " << num_guesses << " tries.\n";
    return 0;
}
