#include <iostream>
#include <string>

using namespace std;

string removeX(string input){
    if(input.length() == 0)
        return input;
    
    if(input[0] == 'x'){
        return removeX(input.substr(1));
    }

    return input[0]+removeX(input.substr(1));
}

int main(){
    string input;
    cin >> input;
    cout << removeX(input);
}