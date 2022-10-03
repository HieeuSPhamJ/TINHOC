#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int N = 32768;

int solve(int n){
    int lg = log2(n);
    int base = (1 << lg);
    if (base == n){
        int d = N - n;
        return log2(d);
    }
    base <<= 1;
    if (base == N){
        return base - n;
    }
    cout << base << " ";
    return log2((base - n) + N - base);
    return -1;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        cout << solve(inp) << endl;
    }
    return 0;
}