#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;


int C(int n){
    return n * (n - 1) / 2;
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    map <int,int> cnt;
    cnt[0] = 1;
    for (int i = 1, pre = 0; i <= n; i++){
        int x;
        cin >> x;
        pre = pre xor min(x, ((1 << k) - 1) xor x);
        cnt[pre]++;
    } 
    int res = 0;
    for (auto i: cnt){
        res += C(i.se / 2);
        res += C(i.se - i.se / 2);
    }
    // cout << res << endl;
    cout << C(n + 1) - res << endl;
    return 0;
}