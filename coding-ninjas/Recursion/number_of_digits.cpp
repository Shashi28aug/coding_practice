#include <iostream>

using namespace std;

int numberOfDigits(int n){
    if(n == 0)
        return 0;
    return numberOfDigits(n/10)+1;
}

int main(){
    int n;
    cin >> n;
    cout << numberOfDigits(n);
}