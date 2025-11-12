#include<bits/stdc++.h>
using namespace std;

void reverseString(string& str) {

    stack<char> s;
    for (char c : str) {
        s.push(c);
    }

    for (int i = 0; i < str.length(); i++) {
        str[i] = s.top();
        s.pop(); 
    }
}

int main() {
    string myString = "DataStructure";
    cout << "Original string: " << myString << endl;

    reverseString(myString);

    cout << "Reversed string: " << myString << endl;

    return 0;
}
