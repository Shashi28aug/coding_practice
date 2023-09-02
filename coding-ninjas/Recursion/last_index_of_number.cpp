#include <iostream>

using namespace std;


int lastIndex(int x, int *input, int n){
    if(n == 0)
        return -1;

    int index = lastIndex(x, input+1, n-1);
    
    return index == -1 ? x == input[0] ? 0 : -1 : index+1;
}

int main(){
    int x, n;
    cin >> x >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    cout << lastIndex(x, input, n);
}