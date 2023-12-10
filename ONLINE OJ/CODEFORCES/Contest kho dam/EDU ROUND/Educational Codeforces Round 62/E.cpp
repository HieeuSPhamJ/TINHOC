#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 2e5 + 10;
const int mod = 998244353;

int add(int a, int b){
    return (a + b) % mod;
}

int mul(int a, int b){
    return (a * b) % mod;
}

int sub(int a, int b){
    return (a - b + mod) % mod;
}

int fpow(int nu, int a){
    if (a == 0){
        return 1;
    }
    if (a == 1){
        return nu;
    }
    int te = fpow(nu, a / 2);
    te = mul(te,te);
    if (a % 2){
        te = mul(te, nu);
    }
    return te;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    deque <int> ts[2];
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ts[i % 2].push_back(x);
    }

    int ans = 1;
    for (int t = 0; t <= 1; t++){
        int cnt = 0;
        deque <int> ls = ts[t];
        while(ls.size() and ls.front() == -1){
            cnt++;
            ls.pop_front();
        }
        int res = fpow(k - 1, cnt);
        cnt = 0;
        while(ls.size() and ls.back() == -1){
            cnt++;
        }
        res = mul(res, fpow(k - 1, cnt));
        int n = (int)ls.size() - 1;
        cnt = 0;
        for (int i = 1, la = a[0]; i <= n; i++){
            if (ls[i] != -1){
                if (ls[i] == la){
                    cout << 0 << endl;
                    return 0;
                }
                if (cnt){
                    int res = fpow(k, cnt);
                    for (int i = 1; i <= cnt; i++){
                        res = sub(res, mul(fpow(k - 1, i - 1), fpow(k, cnt - i)));
                    }
                }
                cnt = 0;
                la = ls[i];
            }
            else{
                cnt++;
            }
        }
    }

    return 0;
}