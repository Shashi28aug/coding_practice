#include <iostream>

using namespace std;

int binary_search(int *arr, int s, int e, int k) {
    if(s > e)
        return -1;
    int m = (s+e)/2;
    if(arr[m] == k)
        return m;
    if(arr[m] < k)
        return binary_search(arr, m+1, e, k);
    if(arr[m] > k)
        return binary_search(arr, 0, m-1, k);
    
    return -1;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int index = binary_search(arr, 0, n-1, k);

    if(index == -1)
        cout << "not found in arrray";
    else 
        cout << index;
}