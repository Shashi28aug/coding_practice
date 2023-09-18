#include <iostream>
#include <string>

using namespace std;

bool checkAB(string input){
    if(input == "")
        return true;
    if(input[0] == 'a')
        return checkAB(input.substr(1));
    if(input[0] == 'b' && input[1] == 'b')
        return checkAB(input.substr(2));
    return false;
}

int main(){
    string input;
    cin >> input;
    if(input[0] == 'a' && checkAB(input.substr(1)))
        cout << "true";
    else
        cout << "false";
}