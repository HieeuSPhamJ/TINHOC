#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

int base, n, k;
int prefix[maxN][2];

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

void sub1(){
    prefix[1][0] = base;
    prefix[1][1] = prefix[1][0] * base;
    for (int i = 2; i <= n / 2 + 1; i++){
        prefix[i][0] = prefix[i - 1][0] + prefix[i - 1][1] + prefix[i - 1][0] * base;
        prefix[i][1] = prefix[i][0] * base;
        if (prefix[i][0] > k){
            cout << (i - 1) * 2 + 1 << endl;
            return;
        }
        if (prefix[i][1] > k){
            cout << i * 2 << endl;
            return;
        }
        if (i > 1000){
            break;
        }
    }
    cout << 0 << endl;
}

void sub2(){
    matrix A(1,2);
    A.data[0][0] = base;
    A.data[0][1] = base * base;
    matrix classic(2,2);
    classic.data[0][0] = 1;
    classic.data[0][1] = base;
    classic.data[1][0] = base + 1;
    classic.data[1][1] = 0;
    int left = 1;
    int right = n / 2 + 1;
    int ans = 1e18;
    while(left <= right){
        int mid = (left + right) / 2;
        matrix B = A;
        if (mid > 1){
            matrix BASE = power(classic, mid - 1);  
            B = A * BASE;
        }    
        if (B.data[0][0] > k){
            ans = min(ans, (mid - 1) * 2 + 1);
            right = mid - 1;
        }
        else if (B.data[0][1] > k){
            ans = min(ans, mid * 2);
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    if (ans == 1e18){
        cout << 0 << endl;
        return;
    }
    cout << ans << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> base >> n >> k;
        // if (n <= 100000){
            sub1();
            // continue;
        // }
        // sub2();
    }
    return 0;
}

/*
    
*/

