#include <iostream>
#include <string>

using namespace std;

string replacePi(string input){;
    if(input.length() == 0)
        return input;
    if(input[0] == 'p' && input[1] == 'i'){
        return "3.14"+replacePi(input.substr(2));
    }

    return input[0] + replacePi(input.substr(1));
}

int main(){
    string input;
    cin >> input;
    cout << replacePi(input);
}