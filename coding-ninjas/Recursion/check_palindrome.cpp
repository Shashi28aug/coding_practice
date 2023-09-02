#include <iostream>
#include <string>

using namespace std;

bool palindrome(string s){
    if(s.length() == 0 || s.length() == 1){
        return true;
    }

    if(s[0] == s[s.length()-1]){
        return(palindrome(s.substr(1, s.length()-2)));
    }

    return false;
}

int main(){
    string s;
    cin >> s;
    if(palindrome(s)){
        cout << "true";
    }else{
        cout << "false";
    }
}