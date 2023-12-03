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

ii a[maxN];

bool cmp(int x, int y){
    if (a[x].se != a[y].se){
        return a[x].se < a[y].se;
    }
    if (a[x].fi != a[y].fi){
        return a[x].fi > a[y].fi;
    }
    return x < y;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int ok = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[i + n].fi = a[i].fi = x;
        ok += x;
    }
    if (ok < n){
        cout << -1 << endl;
        return 0;
    }
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[i + n].se = a[i].se = x;
        if (a[i].fi){
            ls.push_back(i);
        }
    }

    sort(all(ls), cmp);

    // for (auto i: ls){
    //     cout << a[i].se << " ";
    // }
    // cout << endl;
    int res = 1e18;
    int can = 0;
    priority_queue <ii, vector <ii>, greater <ii>> q;
    for (auto st: ls){
        while(q.size()){
            q.pop();
        }
        int tres = 0;
        // cout << "with: " << st << endl;
        for (int i = st; i < st + n; i++){
            can++;
            if (can > 2e6){
                cout << res << endl;
                return 0;
            }
            if (a[i].fi){
                q.push({a[i].se, a[i].fi});
            }
            if (q.size()){
                ii t = q.top();
                q.pop();
                t.se--;
                if (t.se){
                    q.push(t);
                }
                // cout << t.fi << endl;
                tres += t.fi;
            }
            else{
                goto bru;
            }
        }
        res = min(res, tres);
        bru:;
    }
    if (res == 1e18){
        cout << -1 << endl;
        return 0;
    }
    cout << res << endl;
    return 0;
}