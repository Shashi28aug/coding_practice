#include <iostream>
#include <string>

using namespace std;

string removeDuplicate(string input){
    if(input.length() == 0)
        return input;
    
    if(input[0] == input[1]){
        return removeDuplicate(input.substr(1));
    }

    return input[0] + removeDuplicate(input.substr(1));

}
int main(){
    string input;
    cin >> input;
    cout << removeDuplicate(input);
}