#include <iostream>
#include <string>

using namespace std;

void pairStarHelper(char input[], int size){
    if(size == 0)
        return;
    
    pairStarHelper(input+1, size-1);
    
    int arr_size = 0;
    for(int i = 0; input[i] != '\0'; i++)
        arr_size++;
    if(input[0] == input[1]){
        for(int i = arr_size; i >= 0; i--){
            input[i+1] = input[i];
        }
        input[1] = '*';
    }
}

void pairStar(char input[]) {
    int size = 0;
    for(int i = 0; input[i] != '\0'; i++){
        size++;
    }
    

    pairStarHelper(input, size);
    

}
int main(){
    char input[100];
    cin >> input;
    pairStar(input);
    cout << input;
}