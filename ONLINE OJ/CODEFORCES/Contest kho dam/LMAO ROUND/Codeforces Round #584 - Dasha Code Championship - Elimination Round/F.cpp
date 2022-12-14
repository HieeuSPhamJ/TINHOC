#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define iii pair <ii,int>
#define iiii pair <iii,int>
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n, m;
vector <ii> adj[maxN];
iii visited[maxN];
int POW[maxN];
int cntLim = 0;

void print(iii a){
    cout << "(" << a.fi.fi << " " << a.fi.se << " " << a.se << ")";
}

int getLen(int a){
    if (a < 10){
        return 1;
    }
    if (a < 100){
        return 2;
    }
    if (a < 1000){
        return 3;
    }
    if (a < 10000){
        return 4;
    }
    if (a < 100000){
        return 5;
    }
    if (a < 1000000){
        return 6;
    }
    if (a < 10000000){
        return 7;
    }
    if (a < 100000000){
        return 8;
    }
    if (a < 1000000000){
        return 9;
    }
    if (a < 10000000000){
        return 10;
    }
    return 0;
}

ii addupper(ii a, ii b){
    ii res;
    res.fi = POW[getLen(b.se)] * a.fi + b.fi;
    int sum = POW[getLen(b.se)] * a.se + b.se;
    res.fi += sum / mod;
    res.se += sum % mod;
    return res;
}

ii mul(ii a, int b){
    ii res;
    res.fi = a.fi * b;
    res.se = a.se * b;
    res.fi += res.se / mod;
    res.se += res.se % mod;
    return res;
}

iii add(iii a, iii b){
    iii res;
    // print(a);
    // print(b);
    // cout << endl;
    res.fi = addupper(mul(a.fi, POW[getLen(b.se)]), b.fi);
    // res.fi = POW[getLen(b.se)] * a.fi + b.fi;
    int sum = POW[getLen(b.se)] * a.se + b.se;
    res.fi = addupper(res.fi, {0,sum / mod});
    res.se = sum % mod;
    // print(res);
    // cout << endl;
    return res;
}


void init(){
    POW[0] = 1;
    for (int i = 1; i <= n; i++){
        visited[i] = {{inf,inf},inf};
    }
    visited[1] = {{0,0},0};
    for (int i = 1; i < 20; i++){
        (POW[i] = POW[i - 1] * 10) %= mod;
    }
}

void dickcha(){
    priority_queue <iiii,vector<iiii>,greater<iiii>> q;
    q.push({{{0,0},0},1});
    while(!q.empty()){
        iiii t = q.top();
        q.pop();
        // cout << "#" << t.se << endl;
        // if (visited[t.se] != t.fi){
        //     continue;
        // }
        for (auto nu: adj[t.se]){
            cntLim++;
            // if (cntLim >= 1e5 + 10000){
            //     cout << cntLim << " adudarkqua" << endl;
            //     exit(1);
            // }
            iii w = add(t.fi, {{0,0},nu.fi});
            // cout << nu.se << endl;
            if (visited[nu.se] > w){
                visited[nu.se] = w;
                q.push({w,nu.se});
                // cout << "DO" << endl;
            }
        }
        // cout << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    

    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back({i,b});
        adj[b].push_back({i,a});
    }

    init();
    dickcha();
    

    for (int i = 2; i <= n; i++){
        cout << visited[i].se << endl;
    }


    return 0;
}