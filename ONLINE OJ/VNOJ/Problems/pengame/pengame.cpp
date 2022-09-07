#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int mod = 1e9 + 7;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, left, right;
    cin >> n >> k >> left >> right;
    int ans = 0;
    int length = (right - left + 1);
    for (int x = 1; x <= length; x++){
        int len = 1 + (k - 1) * x;
        if (len > length){
            break;
        }
        ans += (length - len + 1);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}