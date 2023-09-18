#include <iostream>
#include <string>

using namespace std;

void keypadCode(int n, string output){
    if(n == 0){
        cout << output << endl;
        return;
    }

    int d = n%10;
    string s;
    if(d == 1)
        s = "";
    else if(d == 2)
        s = "abc";
    else if(d == 3)
        s =  "def";
    else if(d == 4)
        s =  "ghi";
    else if(d == 5)
        s =  "jkl";
    else if(d == 6)
        s =  "mno";
    else if(d == 7)
        s =  "pqrs";
    else if(d == 8)
        s =  "tuv";
    else if(d == 9)
        s =  "wxyz";

    for(int i = 0; i < s.size(); i++){
        keypadCode(n/10, s[i]+output);
    }
}

int main(){
    int n;
    cin >> n;
    keypadCode(n, "");
}