#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int res[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("ROTGAME.inp", "r")) {
        freopen("ROTGAME.inp", "r", stdin);
        freopen("ROTGAME.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, q;
    cin >> n >> k >> q;
    vector <ii> ls;
    while(q--){
        int x, y;
        cin >> x >> y;
        ls.push_back({x,-y});
    }

    reverse(all(ls));
    for (int i = 0; i < n; i++){
        cin >> a[i];
        // cout << a[i] << " ";
    }
    int t = 1;
    for (auto qe: ls){
        if (qe.fi == 1){
            qe.se = ((qe.se % k) + k) % k;
        }
        else{
            qe.se = ((qe.se % n) + n) % n;
            t = (t + qe.se / k) % (n / k);
            qe.se %= k;
        }
    }
    cout << t << endl;

    for (int i = 0; i < n; i++){
        cout << res[i] << " ";
    }

    return 0;
}

/*
3 2 1 0

0123
0-1 = 3
3
1-1 = 0
0
3 1 8 7 4 5 2 6 9
5 3 6 9 7 1 8 2 4
*/