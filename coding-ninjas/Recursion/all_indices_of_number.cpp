#include <iostream>

using namespace std;

int allIndex(int x, int *input, int n, int *output){
    if(n == 0)
        return 0;

    int size = allIndex(x, input+1, n-1, output);
    
    for(int i = 0; i < size; i++){
        output[i] += 1;
    }

    if(input[0] == x){
        for(int i = size ; i > 0; i--){
            output[i] = output[i-1];
        }
        output[0] = 0;
        return size+1;
    }else
        return size;

}

int main(){
    int x, n;
    cin >> x >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    int *output = new int[n];

    int size = allIndex(x, input, n, output);

    for(int i = 0; i < size; i++){
        cout << output[i] << " ";
    }
    cout << endl;
}