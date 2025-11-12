#include<bits/stdc++.h>
using namespace std;

void DiagonalMatrix(int arr[], int n){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(i == j){
                cout << arr[i] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void TriDiagonalMatrix(int arr[], int n){
    int k=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(abs(i-j) <= 1){
                cout << arr[k++] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void LowerTriangularMatrix(int arr[], int n){
    int k=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(i>=j){
                cout << arr[k++] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void UpperTriangularMatrix(int arr[], int n){
    int k=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(i<=j){
                cout << arr[k++] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void SymmetricMatrix(int arr[], int n){
    int k=0;
    int mat[n][n];
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<=i ; j++){
            mat[i][j] = arr[k++];
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            if(i<j) mat[i][j] = mat[j][i];
        }
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int ch,n;
    cout << "1. Diagonal Matrix\n2. Tri-Diagonal Matrix\n3. Lower Triangular\n4. Upper Triangular\n5. Symmetric\n";
    cout << "Enter choice: ";
    cin >> ch;
    cout << "Enter size of matrix (n x n): ";
    cin >> n;

    if(ch==1){
        int *arr = new int[n];
        cout << "Enter " << n << " diagonal elements: ";
        for(int i=0;i<n;i++) cin >> arr[i];
        cout << "Matrix is:" << endl;
        DiagonalMatrix(arr,n);
        delete[] arr;
    }
    else if(ch==2){
        int *arr = new int[3*n-2];
        cout << "Enter " << 3*n-2 << " tri-diagonal elements: ";
        for(int i=0;i<3*n-2;i++) cin >> arr[i];
        cout << "Matrix is:" << endl;
        TriDiagonalMatrix(arr,n);
        delete[] arr;
    }
    else if(ch==3){
        int *arr = new int[n*(n+1)/2];
        cout << "Enter " << n*(n+1)/2 << " lower triangular elements: ";
        for(int i=0;i<n*(n+1)/2;i++) cin >> arr[i];
        cout << "Matrix is:" << endl;
        LowerTriangularMatrix(arr,n);
        delete[] arr;
    }
    else if(ch==4){
        int *arr = new int[n*(n+1)/2];
        cout << "Enter " << n*(n+1)/2 << " upper triangular elements: ";
        for(int i=0;i<n*(n+1)/2;i++) cin >> arr[i];
        cout << "Matrix is:" << endl;
        UpperTriangularMatrix(arr,n);
        delete[] arr;
    }
    else if(ch==5){
        int *arr = new int[n*(n+1)/2];
        cout << "Enter " << n*(n+1)/2 << " symmetric elements (lower triangle): ";
        for(int i=0;i<n*(n+1)/2;i++) cin >> arr[i];
        cout << "Matrix is:" << endl;
        SymmetricMatrix(arr,n);
        delete[] arr;
    }
    else{
        cout << "Wrong choice";
    }

    return 0;
}
