#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

string removeNonStringChars(const string& word) {
    string cleaned;
    for (char c : word) {
        if (isalpha(c) || isspace(c)|| c=='\'') {
            cleaned += c;
        }
    }
    return cleaned;
}

void processFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);

        string word;
        while (iss >> word) {
            string cleanedWord = removeNonStringChars(word);
            if (!cleanedWord.empty()) {
                cout << cleanedWord << " ";
            }
        }

        cout << endl;
    }

    file.close();
}

int main() {
    string filename = "example.txt";
    processFile(filename);

    return 0;
}