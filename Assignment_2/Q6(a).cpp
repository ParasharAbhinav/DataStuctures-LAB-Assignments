#include<bits/stdc++.h>
using namespace std;

void printTriplet(int trip[20][3], int n){
    for(int i=0;i<n;i++){
        cout << trip[i][0] << " " << trip[i][1] << " " << trip[i][2] << endl;
    }
}

int main(){
    int r,c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    int mat[20][20];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> mat[i][j];
        }
    }

    int trip[20][3];
    int value=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]!=0){
                trip[value][0]=i;
                trip[value][1]=j;
                trip[value][2]=mat[i][j];
                value++;
            }
        }
    }
    trip[0][0]=r;
    trip[0][1]=c;
    trip[0][2]=value-1;

    cout << "Original Triplet:" << endl;
    printTriplet(trip,value);

    int t[20][3];
    t[0][0]=trip[0][1];
    t[0][1]=trip[0][0];
    t[0][2]=trip[0][2];

    int k=1;
    for(int col=0;col<trip[0][1];col++){
        for(int i=1;i<value;i++){
            if(trip[i][1]==col){
                t[k][0]=trip[i][1];
                t[k][1]=trip[i][0];
                t[k][2]=trip[i][2];
                k++;
            }
        }
    }

    cout << "Transpose Triplet:" << endl;
    printTriplet(t,value);

    return 0;
}
