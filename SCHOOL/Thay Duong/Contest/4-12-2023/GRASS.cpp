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

const int maxN = 1e5 + 10;
const int inf = 1e18;

int n, m;
ii a[maxN];
int bit[2 * maxN];
int goc[2][2 * maxN];

void update(int i, int v){
    i = m - i + 1;
    // cout << "up " << i << " " << v << endl;
    while(i <= m){
        bit[i] = min(bit[i],v);
        i += i & (-i);
    }
}

int get(int i){
    i = m - i + 1;
    int res = inf;
    // cout << "get " << i << " ";
    while(i){
        res = min(res, bit[i]);
        i -= i & (-i);
    }
    // cout << res << endl;
    return res;
}

void nenso(int te, vector <pair<ii,ii>> &ls){
    vector <int> ts;
    for (auto i: ls){
        ts.push_back(i.se.fi);
        ts.push_back(i.se.fi + 1);
    }
    sort(all(ts));
    ts.erase(unique(all(ts)), ts.end());
    m = ts.size();
    for (auto &i: ls){
        // cout << i.se << ":";
        int t = (lower_bound(all(ts), i.se.fi) - ts.begin()) + 1;
        goc[te][t] = i.se.fi;
        i.se.fi = t;
        // cout << i.se << " ";
    }
    // cout << endl;
}

int res[maxN];

void cal(vector <pair<ii,ii>> ls1, vector <pair<ii,ii>> ls2){
    
    sort(all(ls1));
    sort(rall(ls2));
    // cout << "==LS1==" << endl;
    // for (auto i: ls1){
    //     cout << i.fi.fi << " " << i.fi.se << " " << i.se.fi << endl;
    // }
    // cout << "==LS2==" << endl;
    // for (auto i: ls2){
    //     cout << i.fi.fi << " " << i.fi.se << " " << i.se.fi << endl;
    // }
    // cout << "==solve==" << endl;
    for (int i = 1; i <= m; i++){
        bit[i] = inf;
    }
    for (auto i: ls1){
        while(ls2.size() and ls2.back().fi.fi <= i.fi.fi){
            update(ls2.back().se.fi, ls2.back().fi.se);
            ls2.pop_back();
        }
        int t = get(i.se.fi + 1);
        // cout << i.se.se << ' ' << t << endl;
        if (t == inf){
            res[i.se.se] = -1;
        }
        else{
            res[i.se.se] = t - i.fi.se;
        }
    }
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
    cin >> n;
    vector <pair<ii,ii>> ls[2];
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        if (c == 'N'){
            int x, y;
            cin >> x >> y;
            ls[0].push_back({{x,y}, {x + y, i}});
        }
        else{
            int x, y;
            cin >> x >> y;
            ls[1].push_back({{x,y}, {x + y, i}});
        }
    }
    nenso(0,ls[0]);
    nenso(1,ls[1]);
    
    cal(ls[0], ls[1]);

    for (auto &i: ls[0]){
        swap(i.fi.fi, i.fi.se);
    }
    for (auto &i: ls[1]){
        swap(i.fi.fi, i.fi.se);
    }
    cal(ls[1], ls[0]);
    
    for (int i = 1; i <= n; i++){
        if (res[i] == -1){
            cout << "Infinity" << endl;
            continue;
        }
        cout << res[i] << endl;
    }
    return 0;
}