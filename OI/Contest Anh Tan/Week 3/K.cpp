#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

vector <int> hang;
vector <int> cot;

bool maximize(int &a, int b){
    if (a < b){
        a = b;
        return 1;
    }
    return 0;
}

bool minimize(int &a, int b){
    if (a > b){
        a = b;
        return 1;
    }
    return 0;
}

bool cmp(pair<ii,int> a, pair<ii,int> b){
    return a.se < b.se;
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
    int n, m;
    cin >> n >> m;
    vector <pair<ii,int>> ls;
    hang.resize(n + 2);
    cot.resize(m + 2);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int x;
            cin >> x;
            ls.push_back({{i,j}, x});
        }
    }
    sort(all(ls), cmp);

    int res = 0;
    vector <pair<ii,ii>> ts;
    for (auto i: ls){
        if (ts.size() and ts.back().se.se != i.se){
            for (auto x: ts){
                maximize(hang[x.fi.fi], x.se.fi);
                maximize(cot[x.fi.se], x.se.fi);
            }
            ts.clear();
        }
        int x = i.fi.fi;
        int y = i.fi.se;
        int t = 1 + max(hang[x], cot[y]);
        res = max(res, t);
        // cout << x << " " << y << ": " << t << endl;
        ts.push_back({{x,y},{t,i.se}});
    }
    cout << res << endl;
    return 0;
}