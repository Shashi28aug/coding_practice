#include <iostream>
#include <string>

using namespace std;

int allCodes(string input, string *output) {
    if(input.length() == 0){
        output[0] = "";
        return 1;
    }
    char c = input[0];
    int i = c - '0';
    char ic = 'a'+i-1;

    string res1[10000];
    int size1 = allCodes(input.substr(1), res1);
    int index;
    for(index = 0; index < size1; index++){
    	output[index] = ic + res1[index];
    }

    c = input[1];
    i = 10*i + (c - '0');
    if(i >= 1 && i <= 26){
        char ic2 = 'a'+i-1;
        string res2[10000];
    	int size2 = allCodes(input.substr(2), res2);
        for(int j = 0; j < size2; j++){
        	output[size1+j] = ic2 + res2[j];
    	}
        
        return size1+size2;
    }
    return size1;
}

int main() {
    string input;
    cin >> input;
    string *output = new string[100];
    int size = allCodes(input, output);

    for(int i = 0; i < size; i++){
        cout << output[i];
    }
}