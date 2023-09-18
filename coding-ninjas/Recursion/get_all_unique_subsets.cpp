#include <iostream>

using namespace std;

void subsetOfArray(int *arr, int n, int *output, int m) {
    if(n ==  0) {
        for(int i = 0; i < m; i++){
            cout << output << " ";
        }
        cout << endl;
        return;
    }
    int newOutput[m+1];

    for(int i = 0; i < m; i++){
        newOutput[i] = output[i];
    }
    newOutput[m] = arr[0];
    subsetOfArray(arr+1, n-1, newOutput, m+1);
    subsetOfArray(arr+1, n-1, output, m);
}

int main() {
    int n;
    cin >> n;

    int  *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int *output = new int[n];
    subsetOfArray(arr, n, output, 0);
}