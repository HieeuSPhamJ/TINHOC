#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    // cout << n << " " << k << endl;
    if (k == 1 or n == 1){
        cout << 0;
        return 0;
    }
    if (k - 1 <= n){
        cout << (k - 1) / 2 << endl;
    }
    else{
        int r = n;
        int l = k - n;
        cout << (r - l + 1) / 2 << endl;
    }
    return 0;
}

/*
8 15
15 - 8

7
*/