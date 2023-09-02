#include <iostream>

using namespace std;

void mergeAlgo(int *input, int s, int e){
    
}

void mergeSort(int *input, int s, int e){
    if(s > e){
        return;
    }
    int m = (s+e)/2;
    mergeSort(input, s, m);
    mergeSort(input, m+1, e);
    mergeAlgo(input, s, e);
}
int main(){
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    mergeSort(input, 0, n-1);
}

