#include <iostream>
#include <stack>

using namespace std;

bool redunantParanthesis (string input) {
   
    stack <char> stack;
    
    for(int i = 0; i < input.length();) {
        int count = 0;
        if(input[i] == '(') {
            while (input[i] != ')') {
                stack.push(input[i]);
                i++;
            }
        }

        if(input[i] == ')') {
            while (stack.top() != '(') {
                stack.pop();
                count++;
            }
            if(count <= 1)
               return true;
            stack.pop();
            count == 0;
            i++;
        }

        if(input[i] != ')' && input[i] != '(') {
            i++;
        }

    }

    return false;
}

int main () {
    string input;
    cin >> input;
    cout << ((redunantParanthesis(input)) ? "true" : "false");
}
