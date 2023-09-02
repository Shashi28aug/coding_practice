#include <iostream>

using namespace std;

bool find(int x, int *input, int n){
    if(n == 0)
        return false;
    if(input[0] == x)
        return true;
    return find(x, input+1, n-1);
}
int main(){
    int n, x;
    cin >> n >> x;
    int *input = new int[n];
    for(int i = 0; i < n; i ++){
        cin >> input[i];
    }
    if(find(x, input, n))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}