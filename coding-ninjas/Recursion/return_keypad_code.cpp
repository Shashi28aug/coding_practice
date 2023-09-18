#include <iostream>
#include <string>

using namespace std;

int keypadCode(int n, string output[]) {
    if(n == 0){
        output[0] = "";
        return 1;
    }

    int size = keypadCode(n/10, output);

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
    

    string result[size];
    for(int i = 0; i < size; i++){
        result[i] = output[i];
    }

    int k = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < s.size(); j++){
            output[k++] = result[i]+s[j];
        }
    }

    return k;
}
int main() {
    int n;
    cin >> n;
    string output[1000];
    int size = keypadCode(n, output);
    for(int i = 0; i < n; i++){
        cout << output[i];
    }
}