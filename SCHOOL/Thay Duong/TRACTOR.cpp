#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(ax) ax.begin(), ax.end()
#define rall(ax) ax.rbegin(), ax.rend()
using namespace std;



const int maxN = 1e5 + 10;

int ax[maxN], ay[maxN];
int d1[3 * maxN], d2[3 * maxN];
int n, k;

signed main(){
    // freopen("TRACTOR.INP", "x", stdin);
    // freopen("TRACTOR.OUT", "w", stdout);
    // if (fopen("TRACTOR.inp", "x")) {
    //     freopen("TRACTOR.inp", "x", stdin);
    //     freopen("TRACTOR.out", "w", stdout);
    // }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    int res = 1e18;
    for (int i = 1; i <= n; i++){
	    int x, y;
        cin >> x >> y;  
        ax[x]++;
        ay[y]++;
        d1[x - y + maxN]++;
        d2[x + y]++;
        if (ax[x] == k or ay[y] == k or d1[x - y + maxN] == k or d2[x + y] == k) {
            // cout << i << endl;
            res = min(res,i);
        }
    }
    if (res == 1e18){
        cout << -1;
    }
    else{
        cout << res << endl;
    }
    return 0;
}