#include <iostream>
#include <string>

using namespace std;

int stringToInteger(string input){
    if(input.length() == 1)
        return input[0]-'0';
    return stringToInteger(input.substr(0, input.length()-1))*10 + (input[input.length()-1]-'0');
    
}

int main(){
    string input;
    cin >> input;
    cout << stringToInteger(input);
}