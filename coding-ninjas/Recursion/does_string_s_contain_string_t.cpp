#include <iostream>
#include <string>

using namespace std;

bool stringContain(string s, string t) {
    if(t.length() == 0)
        return true;
    if(s.length() == 0)
        return false;
    
    if(s[0] == t[0]) {
        return stringContain(s.substr(1), t.substr(1));
    }else {
        return stringContain(s.substr(1), t);
    } 
}

int main() {
    string s, t;
    cin >> s >> t;
    if(stringContain(s, t))
        cout << "true";
    else
        cout << "false";
}