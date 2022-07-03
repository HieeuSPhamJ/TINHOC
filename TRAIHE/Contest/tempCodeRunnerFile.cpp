#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;


struct matrix {
  int R, C; 
  vector <vector <long long> > data;
  matrix(int _R, int _C) {
    R = _R; 
    C = _C; 
    data.resize(R); 
    for (int i = 0; i < R; i++) {
      data[i].resize(C, 0); 
    }
  }
  matrix operator *(const matrix &other) {
    matrix ret(R, other.C);
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < other.C; j++) {
        long long sum = 0; 
        for (int k = 0; k < C; k++) {
          sum = (sum + (data[i][k] * other.data[k][j])); 
        }
        ret.data[i][j] = sum; 
      }
    }
    return ret;  
  }

  void print(){
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cout << data[i][j] << ' ';
        }
        cout << endl;
    }
  }
};


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        matrix A(n, n);
        matrix B(n, n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int inp;
                cin >> inp;
                A.data[i][j] = inp;
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                int inp;
                cin >> inp;
                B.data[i][j] = inp;
            }
        }


        matrix C = A * A * A;
        // A.print();
        // cout << endl;
        // B.print();
        // cout << endl;
        // C.print();
        // cout << endl;
        if (C.data == B.data){
            cout << "YES";
        }
        else{
            cout << "NO";
        }

        cout << endl;
    }    

    return 0;
}