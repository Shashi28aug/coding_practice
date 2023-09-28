#include <iostream>
#include <stack>

using namespace std;

int minBracketRev (string input) {
   
    stack <char> stack;
    
    if(input.size()%2 != 0)
        return -1;


    for(int i = 0; i < input.size(); i++){
        if(!stack.empty() && stack.top() == '{' && input[i] == '}'){
            stack.pop(); 
        }
        else if(input[i] == '{'){
            stack.push('{');
            
        }else{
            stack.push('}');
        }
    }
    int count = 0;
    while(!stack.empty()){
        char c1 = stack.top();
        stack.pop();
        char c2 = stack.top();
        stack.pop();
        if(c1 == c2){
            count++;
        }else{
            count += 2;
        }
    }
    
    return count;

}

int main () {
    string input;
    cin >> input;
    cout << minBracketRev(input);
}
