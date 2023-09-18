#include <iostream>

using namespace std;

int subsetSumK(int *arr, int n, int **output, int k) {
    if(n == 0 && k == 0) {
        output[0][0] = 0;
        return 1;
    }else if(n == 0) {
        return 0;
    }

    int **out1 = new int*[100];
    for(int i = 0; i < 100; i++){
        out1[i] = new int[n];
    }
    int **out2 = new int*[100];
    for(int i = 0; i < 100; i++){
        out2[i] = new int[n];
    }
    int size1 = subsetSumK(arr+1, n-1, out1, k-arr[0]);
    int size2 = subsetSumK(arr+1, n-1, out2, k);
    for(int i = 0; i < size1; i++) {
        output[i][0] = out1[i][0]+1;
        output[i][1] = arr[0];
        for(int j = 1; j <= out1[i][0]; j++) {
            output[i][j+1] = out1[i][j];
        }
    }
    for(int i=0;i<size2;i++)
    {
        for(int j=0;j<=out2[i][0];j++)
        {
            output[i+size1][j]=out2[i][j];
        }
    }
    return size1+size2;
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

    int **output = new int*[100];
    for(int i = 0; i < 100; i++){
        output[i] = new int[n];
    }

    int size = subsetSumK(arr, n, output, k);

    for(int i = 0; i < size; i++){
        for(int j = 1; j <= output[i][0]; j++){
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}