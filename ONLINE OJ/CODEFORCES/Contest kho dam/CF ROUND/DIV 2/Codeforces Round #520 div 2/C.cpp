#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;

int a[maxN];
int p[maxN];

int add(int a, int b){
    return (a + b + mod) % mod;
}

int mul(int a, int b){
    return ((a % mod) * (b % mod)) % mod;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int test;
    cin >> test;
    p[1] = 1;
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        a[i] += a[i - 1] + (c - '0');
    }
    for (int i = 2; i <= n + 1; i++){
        p[i] = add(p[i - 1], p[i - 1]);
    }
    while(test--){
        int l, r;
        cin >> l >> r;
        int one = a[r] - a[l - 1];
        int zero = r - l + 1 - one;
        // cout << one << " " << zero << endl;
        int res = (one != 0) * (p[one + 1] - 1);
        int last = res;
        res = add(res,mul(last,p[zero + 1] - 1));
        cout << res << endl;
    }
    return 0;
}