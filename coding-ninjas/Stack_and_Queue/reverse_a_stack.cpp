#include <iostream>
#include <stack>

using namespace std;

void reverseStackHelper(stack<int> &input, stack<int> &extra){
    if(input.empty()){
        return;
    }
    int ans = input.top();
    input.pop();
    reverseStackHelper(input, extra);
    extra.push(ans);
}

void reverseStack(stack<int> &input, stack<int> &extra) {
    reverseStackHelper(input, extra);
    while(!extra.empty()){
        int data = extra.top();
        extra.pop();
        input.push(data);
    }
}

int main () {
    stack <int> input, extra;
    int n;
    cin >> n;
    while (n--) {
        int data;
        cin >> data;
        input.push(data);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
    

}