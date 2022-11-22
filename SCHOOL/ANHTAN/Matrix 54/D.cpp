#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

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

const int maxN = 1e6 + 10;

int Next[maxN];
int notPrime[maxN];

void init(){
    notPrime[0] = notPrime[1] = 1;
    for (int i = 1; i < maxN; i++){
        Next[i] = i;
    }
    for (int i = 2; i * i < maxN; i++){
        if (!notPrime[i]){
            for (int j = 2; i * j <= maxN; j++){
                notPrime[i * j] = 1;
                Next[i * j] = i;
            }
        }
    }    
}

set <int> listPrime;
map <int,int> conv;
vector <ii> primeOf[60];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++){
        int x;
        cin >> x;
        int now = x;
    }

    for (auto prime: )


    return 0;
}
