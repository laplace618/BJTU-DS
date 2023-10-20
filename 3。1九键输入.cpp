#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> digitToLetters(char digit) {
    switch (digit) {
        case '2':
            return {"a", "b", "c"};
        case '3':
            return {"d", "e", "f"};
        case '4':
            return {"g", "h", "i"};
        case '5':
            return {"j", "k", "l"};
        case '6':
            return {"m", "n", "o"};
        case '7':
            return {"p", "q", "r", "s"};
        case '8':
            return {"t", "u", "v"};
        case '9':
            return {"w", "x", "y", "z"};
        default:
            return {""};
    }
}

void generateCombinations(string digits, string current, vector<string>& result) {
    if (digits.empty()) {
        result.push_back(current);
        return;
    }

    char digit = digits[0];
    vector<string> letters = digitToLetters(digit);

    for (const string& letter : letters) {
        generateCombinations(digits.substr(1), current + letter, result);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) {
        return result;
    }

    generateCombinations(digits, "", result);
    return result;
}

int main() {
    string digits;
    cout << "Enter a sequence of digits: ";
    cin >> digits;

    vector<string> combinations = letterCombinations(digits);

    cout << "Letter combinations for " << digits << " are: " << endl;
    for (const string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
