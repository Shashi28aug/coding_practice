#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool balancedParanthesis (string input) {
    if(input.size() == 0)
        return true;
    stack <char> stack;
    for(int i = 0; i < input.size(); i++) {
        if(stack.empty())
            stack.push(input[i]);
        else {
            if(input[i] == ')') {
                if(stack.top() == '(');
                    stack.pop();
            }else if(input[i] == ']') {
                if(stack.top() == '[');
                    stack.pop();
            }
            else
                stack.push(input[i]);
        }
    }

    if(stack.empty())
        return true;
    else
        return false;
}

int main () {
    string input;
    cin >> input;
    cout << ((balancedParanthesis(input)) ? "true" : "false");
}