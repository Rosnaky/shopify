#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>

using namespace std;

void printPrompt(vector<char>& state) {
    cout << "\n\n";

    for (char c : state) cout << c;
    cout << '\n';
    cout << "Enter your guess: \n";
}

bool driver(set<string>& words, string target) {

    int guesses = 5;
    vector<char> state(4, '-')

    cout << "A word has been chosen, please give five guesses for what the word is\n";

    for (int i = 0; i < guesses; i++) {
        printPrompt(state);
    }


}


int main() {

    

}