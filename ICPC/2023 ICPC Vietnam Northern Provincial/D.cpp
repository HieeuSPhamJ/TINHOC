#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int mod = 123456789;

int cur[1 << 16][65];
int la[1 << 16][65];
vector <int> adj[1 << 16];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    if (k > 64){
        cout << 0 << endl;
        return 0;
    }
    if (m > n){
        swap(n,m);
    }
    
    vector <int> ls;
    for (int i = 1; i < (1 << m); i++){
        int ok = 1;
        for (int j = 1; j < m; j++){
            if (i & (1 << j) and i & (1 << (j - 1))){
                ok = 0;
                break;
            }
        }
        if (ok){
            // cout << bitset<16>(i) << endl;
            ls.push_back(i);
        }
    }
    // int cnt = 0;
    for (auto i: ls){
        for (auto j: ls){
            if (i & j){
                break;
            }
            int m = i | j;
            int ok = 1;
            for (int x = 1; x < m; x++){
                if (m & (1 << x) and m & (1 << (x - 1))){
                    ok = 0;
                    break;
                }
            }
            if (ok){
                adj[i].push_back(j);
            }
        }
        // cnt += adj[i].size();
    }
    // cout << cnt << endl;
    
    la[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            for (auto mask: ls){
                int cnt = __builtin_popcount(mask);
                if (j < cnt){
                    break;
                }
                    cout << bitset<2>(mask) << ' ' << j << ": " << la[mask][j] << endl;
                for (auto pmask: adj[mask]){
                    cur[mask][j] += la[pmask][j - cnt];
                }
            }
        }
        for (int j = 0; j <= k; j++){
            for (auto mask: ls){
                la[mask][j] = cur[mask][j];
                cur[mask][j] = 0;
                if (la[mask][j]){
                }
            }
        }
    }

    int res = 0;
    for (auto i: ls){
        res += la[i][k];
    }

    cout << res << endl;
    return 0;
}