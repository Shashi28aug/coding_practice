#include <iostream>
#include <queue>

using namespace std;

void reverseQueue(queue<int> &input) {
    if(input.empty())
        return;

    int data = input.front();
    input.pop();
    reverseQueue(input);
    input.push(data);
    
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        queue <int> input;
        int n;
        cin >> n;
        while (n--) {
            int data;
            cin >> data;
            input.push(data);
        }

        reverseQueue(input);

        while (!input.empty()) {
            cout << input.front() << " ";
            input.pop();
        }
    }
}