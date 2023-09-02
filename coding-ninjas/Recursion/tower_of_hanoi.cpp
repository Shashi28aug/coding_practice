#include <iostream>
#include <string>

using namespace std;

void towerOfHanoi(char s, char a, char d,int n){
    if(n == 0)
        return;
    if(n == 1){
        cout << s << ' ' << d << endl;
        return;
    }

    towerOfHanoi(s, d, a, n-1);
    cout << s << ' ' << d << endl;
    towerOfHanoi(a, s, d, n-1);
}

int main(){
    int n;
    cin >> n;
    towerOfHanoi('s', 'a', 'd', n);
}