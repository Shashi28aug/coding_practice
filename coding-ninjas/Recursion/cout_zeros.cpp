#include <iostream>

using namespace std;

int count(int n){
    if(n == 0)
        return 1;
    if(n > 0 and n < 10)
        return 0;
    int res = count(n/10);
    if(n%10 == 0)
        return res+1;
    return res;
}
int main(){
    int n;
    cin >> n;
    cout << count(n);
}