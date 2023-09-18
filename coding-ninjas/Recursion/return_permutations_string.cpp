#include <iostream>
#include <string>

using namespace std;

int permutationsString(string input, string *output) {
    if(input.length() == 0) {
        output[0] = "";
        return 1;
    }

    int k = 0;
    for(int i = 0; i < input.size(); i++) {
        string *smallOutput = new string[1000];
        int size = permutationsString(input.substr(0, i)+input.substr(i+1,input.size()-i-1), smallOutput);
        for(int j = 0; j < size; j++) {
            output[k] = input[i] + smallOutput[j];
            k++;
        }
    }

    return k;
}

int main() {
    string input;
    cin >> input;
    string *output = new string[1000];
    int size = permutationsString(input, output);

    for(int i = 0; i < size; i++) {
        cout << output[i] << endl;
    }

}