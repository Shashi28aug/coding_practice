#include <iostream>

using namespace std;

int firstIndex(int x, int *input, int n){
    if(n == 0)
        return -1;
    if(input[0] == x)
        return 0;
    
    int index = firstIndex(x, input+1, n-1);
    return index == -1 ? -1 : index+1; 
}

int main(){
    int x, n;
    cin >> x >> n;
    int *input = new int[n];
    for(int i  = 0; i < n; i++){
        cin >> input[i];
    }
    cout << firstIndex(x, input, n);
}