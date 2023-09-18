#include <iostream>

using namespace std;


bool splitArray(int *input, int n, int ls, int rs) {
    if(n == 0 && ls == rs)
        return true;
    if(n == 0)
        return false;

    if(input[0]%5 == 0)
        return splitArray(input+1, n-1, ls+input[0], rs);
    else if(input[0]%3 == 0)
        return splitArray(input+1, n-1, ls, rs+input[0]);
    else
        return splitArray(input+1, n-1, ls+input[0], rs) || splitArray(input+1, n-1, ls, rs+input[0]);
    
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    if(splitArray(input, n, 0, 0))
        cout << "true";
    else
        cout << "false";
}