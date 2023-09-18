#include <iostream>
#include <string>

using namespace std;

void permutationsString(string input, string output) {
    if(input.length() == 0) {
        cout << output << endl;
        return;
    }

    for(int i = 0; i < input.size(); i++) {
        permutationsString(input.substr(0, i)+input.substr(i+1,input.size()-i-1), output+input[i]);
    }
}

int main() {
    string input;
    cin >> input;
    permutationsString(input, "");
}