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

const int maxN = 5e5 + 10;

int a[maxN];
int b[maxN];
ii c[maxN];

bool cmp(ii x, ii y){
    if (x.se == y.se){
        return b[x.fi] < b[y.fi];
    }
    return x.se < y.se;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("GYM.inp", "r")) {
        freopen("GYM.inp", "r", stdin);
        freopen("GYM.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        c[i].se += a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        c[i].se += b[i];
        c[i].fi = i;
    }

    sort(c + 1, c + 1 + n, cmp);
    int res = 0;
    priority_queue <int> q;
    for (int i = 1, s = 0; i <= n; i++){
        int id = c[i].fi;
        // cout << id << " ";
        if (s <= b[id]){
            q.push(a[id]);
            s += a[id];
        }
        else if (s - q.top() <= b[id]){
            s -= q.top();
            q.pop();
            q.push(a[id]);
            s += a[id];
        }
        res = max(res, (int)q.size());
    }
    // cout << endl;

    cout << res << endl;

    return 0;
}

/*

*/