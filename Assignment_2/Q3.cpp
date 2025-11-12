#include<bits/stdc++.h>
using namespace std;
void BinarySearch(int arr[] , int n){
    int number;
    cout << "Enter no to search: ";
    cin >> number;
    int s = 0; int e = n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid] == number){
            cout << "Number found at index : " << mid<<endl;
            return;
        }
        else if(arr[mid] < number){
            s++;
        }
        else{
            e++;
        }
    }
}
int main(){
    int n;
    cout << "Enter no of elements: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    BinarySearch(arr, n);
    return 0;
}