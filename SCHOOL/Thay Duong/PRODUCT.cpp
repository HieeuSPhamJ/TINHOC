#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int len(int n){
    if (n == 0){
        return 1;
    }
    return log2(n);
}

signed main(){
    freopen("PRODUCT.INP", "r", stdin);
    freopen("PRODUCT.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int j = (n xor i);
        if (len(i) <= len(n) and len(j) <= len(n)){
            ans = max(ans, i * j);
        }
    }
    cout << ans;
    return 0;
}