#include <iostream>
#include <stack>

using namespace std;

void stockSpan (int *price, int n) {
    if(n == 0){
        cout << -1;
        return;
    }
    int *result = new int[n];
    stack <int> stack;

    for (int i = 0; i < n; i++) {
        if(stack.empty()) {
            stack.push(i);
            result[i] = 1;
        }else {
            if(price[i] <= price[stack.top()]) {
                result[i] = i-stack.top();
                stack.push(i);
            }else {
                while (!stack.empty() && (price[stack.top()] < price[i])) {
                    stack.pop();
                }
                if(stack.empty()){
                    result[i] = i+1;
                }else {
                    result[i] = i-stack.top();
                }
                stack.push(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
}

int main () {
    int n;
    cin >> n;
    int *price = new int[n];
    for (int i = 0; i< n; i++) {
        cin >> price[i];
    }
    stockSpan(price, n);
}
