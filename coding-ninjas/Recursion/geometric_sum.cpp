#include <iostream>
#include <math.h>

using namespace std;

double geometricSum(int n){
    if(n == 0)
        return 1;
    double gSum = geometricSum(n-1);
    double k = n;

    return 1/pow(2.0, n)+gSum;
}

int main(){
    int n;
    cin >> n;
    cout << geometricSum(n);
}