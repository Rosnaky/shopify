#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>

using namespace std;

void printPrompt() {
    cout << "\n\n";

    // for (char c : state) cout << c;
    // cout << '\n';
    cout << "Enter your guess: \n";
}

vector<char> getState(string guess, string target) {
    /*
    actual: wood
    guess: okol
    --1-
    */
   vector<char> ans(4, '-');
   vector<bool> inGuess(26);
   vector<bool> inTarget(26);

   for (int i = 0; i < 4; i++) {
        if (target[i] == guess[i]) {
            ans[i] = '1';
            inGuess[guess[i]-'a'] = 1;
        }
        inTarget[target[i]-'a'] = 1;
   }

//    for (int i = 0; i < 26; i++) cout << char(i+'a') << inGuess[i] << " "; cout << endl;
//    for (int i = 0; i < 26; i++) cout << char(i+'a') << inTarget[i] << " "; cout << endl;

   for (int i = 0; i < 4; i++) {
        if (ans[i] == '1') continue;
        // cout << (guess[i]);
        if (inTarget[guess[i]-'a'] && !inGuess[guess[i]-'a']) {
            ans[i] = '0';
        }
   }

    return ans;
   
}

bool win(vector<char>& state) {
    for (char c : state) {
        if (c != '1') return 0;
    }

    return 1;
}

bool validGuess(set<string>& words, string word) {
    return (words.find(word) != words.end()) && word.size() == 4;
}

bool driver(set<string>& words, string target) {

    int guesses = 5;
    // vector<char> state(4, '-');

    cout << "A word has been chosen, please give five guesses for what the word is\n";

    for (int i = 0; i < guesses; i++) {
        printPrompt();
        string guess; cin >> guess;
        // TODO: check if guess is valid
        if (!validGuess(words, guess)) {
            cout << "Invalid guess. Please choose a valid 4-letter word\n";
            i--;
            continue;
        }

        vector<char> state = getState(guess, target);

        cout << "Result: ";

        for (char c : state) cout << c;
        cout << '\n';

        if (win(state)) {
            cout << "You guessed the word!\n";
            return 1;
        }
    }

    cout << "The word was: " << target << '\n';

    return 0;


}


int main() {

    set<string> words = {"able", "bell", "boss", "cast", "cash", "knot", "note", "near", "over", "salt", "wood", "okol"};
    string target = "knot";

    int res = driver(words, target);

}