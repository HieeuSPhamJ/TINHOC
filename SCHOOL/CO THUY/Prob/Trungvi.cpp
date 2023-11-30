#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;

int pre[maxN];
int cnt[2][2 * maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("Trungvi.inp", "r")) {
        freopen("Trungvi.inp", "r", stdin);
        freopen("Trungvi.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int la = 1e18;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        pre[i] = pre[i - 1];
        if (x < k){
            pre[i]--;
        }
        else if (x > k){
            pre[i]++;
        }
        else{
            la = min(la, i);
        }
        // cout << pre[i] << " ";
    }
    // cout << endl;

    int res = 0;
    for (int i = 0; i < la; i++){
        cnt[i % 2][pre[i] + n]++;
    }
    for (int i = la; i <= n; i++){
        res += cnt[!(i % 2)][pre[i] + n];
        cnt[i % 2][pre[i] + n]++;
    }
    cout << res << endl;
    return 0;
}