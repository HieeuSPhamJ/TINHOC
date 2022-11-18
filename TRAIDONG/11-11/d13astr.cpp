#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e7 + 10;
const int mod = 111539786;

// int dp[maxN][6];
int nextStep[8][3];

int mul(int a, int b){
    return (a * b) % mod;
}

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

int fastpow(int n, int a){
    if (a == 1){
        return n;
    }
    int temp = fastpow(n, a / 2);
    int ans = mul(temp, temp);
    if (a % 2){
        return mul(ans, n);
    }
    else{
        return ans;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string s;
    while(cin >> n >> s){
        memset(nextStep,0,sizeof(nextStep));
        int m = s.length();
        for (int i = 0; i <= m; i++){
            string t = s.substr(0,i);
            string t0 = t + "0";
            string t1 = t + "1";
            // cout << "With: " << t << endl;
            for (int j = 0; j < t0.length(); j++){
                int len = t0.length() - j;
                // cout << t0.substr(j, len) << " " << s.substr(0, len) << endl;
                if (t0.substr(j, len) == s.substr(0, len)){
                    // cout << len << endl;
                    nextStep[i][0] = len;
                    break;
                }
            }
            for (int j = 0; j < t1.length(); j++){
                int len = t1.length() - j;
                if (t1.substr(j, len) == s.substr(0, len)){
                    nextStep[i][1] = len;
                    break;
                }
            }
        }

        // for (int i = 0; i <= m; i++){
        //     cout << nextStep[i][0] << " " << nextStep[i][1] << endl;
        // }

        matrix base(m, m);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < m; j++){
                base.data[i][j] += (nextStep[i][0] == j);
                base.data[i][j] +=(nextStep[i][1] == j);
            }
        }

        matrix A(1,m);
        A.data[0][0] = 1;
        A.data[0][1] = 1;
        matrix B = A;
        int ans = 0;
        if (n != 1){
            
            matrix powBase = power(base, n - 1);
            B = A * powBase;
        }
        for (int i = 0; i < m; i++){
            (ans += B.data[0][i]) %= mod;
            // cout << B.data[0][i] << " ";
        }

        cout << ans << endl;
    }


    return 0;
}