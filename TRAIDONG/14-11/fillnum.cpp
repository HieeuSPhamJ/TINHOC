#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <ii,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e7 + 10;

int nxt[maxN];
int ded[maxN];
int ans[maxN];
iii shots[100010];

int findNxt(int i) {
	return ded[nxt[i]] == 0 ? nxt[i] : nxt[i] = findNxt(nxt[i]);
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        cin >> shots[i].fi.fi;
        cin >> shots[i].fi.se;
        cin >> shots[i].se;
    }
    for (int i = 0; i <= n + 2; i++){
        nxt[i] = i + 1;
    }
    for(int xx = m; xx >= 1; xx--){
        iii shot = shots[xx];
        // cout << shot.se << ":" << endl;
        for (int i = findNxt(shot.fi.fi - 1); i <= shot.fi.se; i = findNxt(i)){
            ans[i] = shot.se;
            ded[i] = 1;
            // cout << i << " ";
        }
        // cout << endl;
    }
    int res = 0;
    for (int i = n, t = 1; i >= 1; i--){
        // cout << ans[i];
        (res += (ans[i] * t) % k) %= k;
        (t *= 10) %= k;
    }
    cout << res;
    return 0;
}