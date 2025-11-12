#include<bits/stdc++.h>
using namespace std;
void concate(){
    string a , b;
    cout << "Enter 1st string : ";
    cin >> a;
    cout << "Enter 2nd string : ";
    cin >> b;
    string c = a + b;
    cout << c;
}
void reverseStr(){
    string a;
    cout << "Enter string : ";
    cin >> a;
    int i = 0, j = a.length() - 1;
    while(i < j){
        swap(a[i], a[j]);
        i++;
        j--;
    }
    cout << a;
}
void deleteVowels(){
    string s;
    cout << "Enter string : ";
    cin >> s;
    string result = "";
    for(char c : s){
        if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u' &&
           c!='A' && c!='E' && c!='I' && c!='O' && c!='U'){
            result += c;
        }
    }
    cout <<result << endl;
}
void sortString() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    int n = s.length();
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(s[j] > s[j+1]) {
                char temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
    cout << "Sorted string: " << s << endl;
}
void Lowercase() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a'; 
        }
    }
    cout << "Lowercase: " << s << endl;
}
int main(){
    concate();
    reverseStr();
    deleteVowels();
    sortString();
    Lowercase();
    return 0;

}
