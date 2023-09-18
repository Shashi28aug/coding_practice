#include <iostream>

using namespace std;

void subsetSumK(int *arr, int n, int *output, int m, int k) {
    if(n == 0 && k == 0) {
        for(int i = 0; i < m; i++) {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }else if(n == 0)
        return;

    subsetSumK(arr+1, n-1, output, m, k);
    output[m] = arr[0];
    subsetSumK(arr+1, n-1, output, m+1, k-arr[0]);
}

int main() {
    int n;
    cin >> n;

    int  *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int *output = new int[n];
    subsetSumK(arr, n, output, 0, k);
}