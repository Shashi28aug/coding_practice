#include <iostream>

using namespace std;

int quickSortAlgo(int *input, int s, int e) {
    int pivot = input[s];
    int count = 0;
    for(int i = s+1; i <= e; i++){
        if(input[i] <= pivot)
            count++;
    }
    int pivotIndex = s+count;
    int temp = input[s];
    input[s] = input[pivotIndex];
    input[pivotIndex] = temp;

    int i = s, j = pivotIndex+1;
    while( i < pivotIndex && j <= e){
        if(input[i] <= pivot)
            i++;
        else if(input[j] > pivot)
            j++;
        else{
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j++;
        }
    }

    return pivotIndex;
}

void quickSort(int *input, int s, int e) {
    if(s >= e)
        return;
    
    int p = quickSortAlgo(input, s, e);
    quickSort(input, s, p-1);
    quickSort(input, p+1, e);
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, 0, n-1);

    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
}