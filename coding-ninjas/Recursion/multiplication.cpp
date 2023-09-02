#include <iostream>

using namespace std;

int multiply(int n, int m){
    if(n == 0 || m == 0)
        return 0;
    if(n == 1)
        return m;
    if(m == 1)
        return n;
    
    return multiply(n-1, m)+m;
}

int main(){
    int n, m;
    cin >> n >> m;

    cout << multiply(n, m);
}