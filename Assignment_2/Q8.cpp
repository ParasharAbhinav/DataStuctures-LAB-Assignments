#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[50];
    cout << "Enter elements: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr, arr+n); 

    int count = 1;    
    for(int i=1;i<n;i++){ 
        if(arr[i] != arr[i-1]){
            count++;
        }
    }

    cout << "Number of distinct elements: " << count << endl;
    return 0;
}

