#include <iostream>

using namespace std;

void mergeAlgo(int *input, int s, int e){
    int m = (s+e)/2;
    int i = s, j = m+1, k = 0;
    int arr[100];
    while(i <= m && j <= e){
        if(input[i] < input[j]){
            arr[k] = input[i];
            i++;
            k++;
        }
        else if(input[i] > input[j]){
            arr[k] = input[j];
            j++;
            k++;
        }else{
            arr[k] = input[i];
            i++;
            k++;
            arr[k] = input[j];
            j++;
            k++;
        }
    }

    while (i <= m)
    {
        arr[k] = input[i];
        i++;
        k++;
    }

    while (j <= e)
    {
        arr[k] = input[j];
        j++;
        k++;
    }
    i = s;
    for(k = 0; k < e-s+1; k++){
        input[i] = arr[k];
        i++;
    }
    

}

void mergeSort(int *input, int s, int e){
    if(s >= e){
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
    
    for(int i = 0; i < n; i++){
        cout  << input[i] << " ";
    }
}

