#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int n, k;
int ans = 1e9;
int a[200];

void backtrack(int i, int open, int cover, int res){
    if (cover > k){
        return;
    }
    // cout << i << " " << open << " " << cover << " " << res << endl;
    if (i >= n){
        // cout << cover << " " << res << endl;
        if (cover <= k){
            ans = min(ans, res);
        }
        return;
    }
    if (open){
        backtrack(i + 1, 1, cover + 1, res);
        if (a[i + 1] >= 20){
            backtrack(i + 1, 0, cover, res + 1);
        }
    }
    else{
        backtrack(i + 1, 1, cover + 1, res + 1);
        if (a[i + 1] >= 20){
            backtrack(i + 1, 0, cover, res);
        }
    }

}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    backtrack(0,0,0,0);
    if (ans == 1e9){
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}