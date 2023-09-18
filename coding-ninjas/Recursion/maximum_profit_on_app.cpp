#include <iostream>
#include <algorithm>

using namespace std;

int maxProfit(int *input, int n) {
    sort(input, input+n);

    int maxOutput = 0;
    for(int i = 0; i < n; i++) {
        int output = input[i]*(n-i);
        maxOutput = max(maxOutput, output);
    }

    return maxOutput;
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    cout << maxProfit(input, n);
}