#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

map <int,int> cnt[2];
map <int,int> tres;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (m % x){
            continue;
        }
        cnt[0][x]++;
    }
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (m % x){
            continue;
        }
        cnt[1][x]++;
    }

    for (auto i: cnt[1]){
        int v = i.fi;
        int num = i.se;
        // cout << v << " " << num << endl;
        for (auto j: cnt[0]){
            ii t = j;
            if (t.fi * v > m){
                break;
            }
            if (m % t.fi){
                continue;
            }
            // cout << t.fi * v << ": " << t.fi << " " << v << " " << t.se << " " << num << endl;
            tres[t.fi * v] += t.se * num;
        }
    }

    int res = 0;

    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (m % x){
            continue;
        }
        res += tres[m / x];
    }

    cout << res << endl;

    return 0;
}