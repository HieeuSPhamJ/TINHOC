#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

unordered_map <int,int> cnt[4];
unordered_map <int,int> tres;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int x = i;
        if (m % x){
            continue;
        }
        cnt[1][x]++;
    }
    for (int i = 1; i <= n; i++){
        int x = i;
        if (m % x){
            continue;
        }
        cnt[2][x]++;
    }

    for (auto i: cnt[2]){
        int v = i.fi;
        int num = i.se;
        // cout << v << " " << num << endl;
        for (int j = 1; v * j <= m; j++){
            if (m % j){
                continue;
            }
            // cout << j * v << ": " << j << " " << v << " " << cnt[1][j] << " " << num << endl;
            tres[j * v] += cnt[1][j] * num;
        }
    }

    int res = 0;

    for (int i = 1; i <= n; i++){
        int x = i;
        if (m % x){
            continue;
        }
        res += tres[m / x];
    }

    cout << res << endl;

    return 0;
}