#include <iostream>

using namespace std;

int subsetOfArray(int *arr, int n, int **output) {
    if(n == 1){
        output[0][0] = 1;
        output[0][1] = arr[0];
        return 1;
    }

    int size = subsetOfArray(arr+1, n-1, output);

    output[size][0] = 1;
    output[size][1] = arr[0];

    for(int i = 0; i < size; i++){
        output[i+size+1][0] = output[i][0]+1;
        output[i+size+1][1] = arr[0];
        for(int j = 2; j <= output[i+size+1][0]; j++){
            output[i+size+1][j] = output[i][j-1];
        }
    }
    return 2*size+1;
}


int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int **output = new int*[100];
    for(int i = 0; i < 100; i++){
        output[i] = new int[n];
    }

    int size = subsetOfArray(arr, n, output);

    for(int i = 0; i < size; i++){
        for(int j = 1; j <= output[i][0]; j++){
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

}