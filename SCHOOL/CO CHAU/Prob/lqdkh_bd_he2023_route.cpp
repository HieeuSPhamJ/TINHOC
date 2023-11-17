#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define iii pair <int,ii>
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

unordered_map <int,int> nen;
int goc[maxN];
int MAXVAL = 0;

void nenso(vector <ii> &ls){
    vector <int> s;
    for (auto i: ls){
        s.push_back(i.fi);
        s.push_back(i.se);
    }
    sort(all(s));
    s.resize(distance(s.begin(), unique(all(s))));
    vector <int> ts;
    ts.push_back(s.front());
    for (int i = 1; i < s.size(); i++){
        ts.push_back(s[i]);
        ts.push_back(s[i - 1]);
        if (s[i] - s[i - 1] == 1){
            continue;
        }
        if (s[i] - s[i - 1] == 2){
            ts.push_back(s[i] - 1);
            continue;
        }
        ts.push_back(s[i] - 1);
        ts.push_back(s[i - 1] + 1);
    }

    sort(all(ts));
    
    int cnt = 0;
    for (auto i: s){
        cnt++;
        nen[i] = cnt;
        goc[cnt] = i;
    }
    MAXVAL = max(MAXVAL, ts.back());

    for (auto &i: ls){
        i.fi = nen[i.fi];
        i.se = nen[i.se];
    }
}

int vis[410][410];
int cannot[410][410];

ii d[]{
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

bool checkin(ii nu){
    if (nu.fi < 0 or nu.fi > MAXVAL or nu.se < 0 or nu.se > MAXVAL){
        return 0;
    }
    return 1;
}

int getval(ii a, ii b){
    a.fi = goc[a.fi];
    a.se = goc[a.se];
    b.fi = goc[b.fi];
    b.se = goc[b.se];
    // cout << a.fi << " " << a.se << " " << b.fi << " " << a.se << endl; 
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}

signed main(){
    //freopen("route.INP", "r", stdin);
    //freopen("route.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <ii> ls;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        ls.push_back({a,b});
    }
    ls.push_back(ls.front());
    nenso(ls);

    for (auto i: ls){
        cannot[i.fi][i.se] = 1;
    }
    priority_queue <iii,vector <iii>, greater <iii>> q;
    int res = 0;
    // for (auto i: ls){
    //     cout << i.fi << " " << i.se << endl;
    // }
    for (int i = 0; i < n; i++){
        for (int x = 1; x <= 400; x++){
            for (int y = 1; y <= 400; y++){
                vis[x][y] = 1e18;
            }
        }
        for (auto x: ls){
            cannot[x.fi][x.se] = 1;
        }
        cannot[ls[i + 1].fi][ls[i + 1].se] = 0;
        q.push({0, ls[i]});
        vis[ls[i].fi][ls[i].se] = 0;
        while(!q.empty()){
            iii t = q.top();
            q.pop();
            if (vis[t.se.fi][t.se.se] != t.fi){
                continue;
            }
            // cout << t.se.fi << " " << t.se.se << ": " << endl;
            for (int di = 0; di < 4; di++){
                ii nu = t.se;
                nu.fi += d[di].fi;
                nu.se += d[di].se;
                if (!checkin(nu)){
                    continue;
                }
                int w = t.fi + getval(nu, t.se);
                if (vis[nu.fi][nu.se] > w and cannot[nu.fi][nu.se] == 0){
                    vis[nu.fi][nu.se] = w;
                    q.push({w, nu});
                    // cout << nu.fi << "," << nu.se << "|" << w << " ";
                }
            }
            // cout << endl;
        }
        // cout << i << ": " << vis[ls[i + 1].fi][ls[i + 1].se] << endl;
        if (vis[ls[i + 1].fi][ls[i + 1].se] == 1e18){
            cout << -1 << endl;
            return 0;
        }
        res += vis[ls[i + 1].fi][ls[i + 1].se];
        // break;
    }

    // cout << getval({2,2}, {3,2}) << endl;

    cout << res << endl;
    return 0;
}