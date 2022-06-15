#include<bits/stdc++.h>
#define matr vector <vector <int>>
using namespace std;


matr multiMatrix2x2(matr A, matr B){
    matr C = {{A[0][0] * B[0][0] + A[0][1] * B[1][0], A[0][0] * B[0][1] + A[0][1] * B[1][1]},
            {A[1][0] * B[0][0] + A[1][1] * B[1][0], A[1][0] * B[0][1] + A[1][1] * B[1][1]}}; 
    return C;
}



matr powMatrix(matr A, int n){
    if (n == 1){
        return A;
    }
    matr tempPow = powMatrix(A, n / 2);
    if (n % 2 == 1){
        return multiMatrix2x2(multiMatrix2x2(tempPow, tempPow), A);
    }
    return multiMatrix2x2(tempPow, tempPow);
}

 int main(){
     int test;
     cin >> test;
     while(test--){
        int n;
        cin >> n;
        if (n == 1){
            cout << 1 << endl;
            continue;
        }
        if (n == 2){
            cout << 2 << endl;
            continue;
        }
        matr matrix = {{1, 1}, {1, 0}};
        matrix = powMatrix(matrix, n - 2);

        // cout << matrix[0][0] << matrix[0][1] << endl;
        // cout << matrix[1][0] << matrix[1][1] << endl;

        cout << matrix[0][0] + matrix[0][1] + matrix[1][0] + matrix[1][1] << endl;

     }

     return 0;
 }