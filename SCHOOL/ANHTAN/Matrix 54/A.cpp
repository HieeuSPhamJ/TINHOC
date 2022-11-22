#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 111539786;

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
          sum = (sum + (data[i][k] * other.data[k][j]) % mod) % mod; 
        }
        ret.data[i][j] = sum; 
      }
    }
    return ret;  
  }
};

matrix power(const matrix &M, int n) {
  if (n == 1) {
    return M; 
  }
  else {
    matrix ret = power(M, n / 2); 
    ret = ret * ret; 
    if (n % 2 == 1) {
      ret = ret * M; 
    }
    return ret; 
  }
}




signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    matrix base(2,2);
    matrix A(1,2);
    A.data[0][0] = 1;
    A.data[0][1] = 1;
    base.data[0][0] = 0;
    base.data[0][1] = 1;
    base.data[1][0] = 1;
    base.data[1][1] = 1; 
    while(test--){
        int n;
        cin >> n;
        if (n == 1){
            cout << 1 << endl;
            continue;
        }

        matrix BASE = power(base, n - 1);
        matrix B = A * BASE;
        cout << B.data[0][1] << endl;

    }
    return 0;
}
