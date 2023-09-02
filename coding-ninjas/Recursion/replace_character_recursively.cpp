#include <iostream>
#include <string>

using namespace std;

string removeChar(string input, char c1, char c2){
    if(input.length() == 0)
        return input;
    if(input[0] == c1){
        return c2 + removeChar(input.substr(1), c1, c2);
    }

    return input[0] + removeChar(input.substr(1), c1, c2);
}

int main(){
    string input;
    char c1, c2;
    cin >> input >> c1 >> c2;
    cout << removeChar(input, c1, c2);
}