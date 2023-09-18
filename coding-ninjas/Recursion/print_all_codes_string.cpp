#include <iostream>
#include <string>

using namespace std;

void allCodes(string input, string output) {
    if(input.length() == 0) {
        cout << output << endl;
        return;
    }

    char c = input[0];
    int i = c - '0';
    char ic = 'a'+i-1;
    allCodes(input.substr(1), output+ic);
    c = input[1];
    i = 10*i + (c - '0');
     if(i >= 1 && i <= 26){
        char ic2 = 'a'+i-1;
    	allCodes(input.substr(2), output+ic2);
    }
}

int main() {
    string input;
    cin >> input;
    allCodes(input, "");
}