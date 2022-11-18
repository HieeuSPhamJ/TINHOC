#include<bits/stdc++.h>
#define ii pair <int,int>
#define iiiii pair <pair<ii,ii>,int>
#define fi first
#define se second
#define int long long
#define double long double
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;

const int maxN = 510;

int n, m, D;
int a[maxN][maxN];
int ans[maxN][maxN];
ii father[maxN][maxN];
int cnt = 0;
ii d[] = {
    {0,-1},
    {-1,0}
};
int sizeCom[maxN][maxN];
vector <ii> listStart[maxN][maxN];

bool checkOut(ii nude){
    if (1 <= nude.fi and nude.fi <= n and 1 <= nude.se and nude.se <= m){
        return 0;
    }
    return 1;
}

bool cmp(iiiii a, iiiii b){
    return a.se > b.se;
}

ii who(ii nude){
    if (father[nude.fi][nude.se] == nude){
        return nude;
    }
    return father[nude.fi][nude.se] = who(father[nude.fi][nude.se]);
}

void connect(ii x, ii y, int we){
    ii u = who(x);
    ii v = who(y);
    if (u == v){
        return;
    }
    if (listStart[u.fi][u.se].size() > listStart[v.fi][v.se].size()){
        swap(u,v);
    }
    for (auto i: listStart[u.fi][u.se]){
        listStart[v.fi][v.se].push_back(i);
    }
    listStart[u.fi][u.se].clear();
    sizeCom[v.fi][v.se] += sizeCom[u.fi][u.se];
    father[u.fi][u.se] = father[v.fi][v.se];
    if (sizeCom[v.fi][v.se] >= D){
        for (auto i: listStart[v.fi][v.se]){
            // cout << x.fi << "," << x.se << " " << y.fi << "," << y.se << " " << we << endl;
            ans[i.fi][i.se] = min(ans[i.fi][i.se],we);
            cnt--;
        }
        listStart[v.fi][v.se].clear();
    }

}

signed main(){
    freopen("SKILEVEL.INP", "r", stdin);
    freopen("SKILEVEL.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> D;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            father[i][j] = {i,j};
            sizeCom[i][j] = 1;
            ans[i][j] = 1e18;
            cin >> a[i][j];
        }
    }

    if (D == 0 or D == 1){
        cout << 0;
        return 0;
    }
    vector <iiiii> E;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int s;
            cin >> s;
            if (s){
                listStart[i][j].push_back({i,j});
                cnt++;
            }
            for (int x = 0; x < 2; x++){
                ii nu = {i,j};
                nu.fi += d[x].fi;
                nu.se += d[x].se;
                if (checkOut(nu)){
                    continue;
                }
                int weeee = abs(a[i][j] - a[nu.fi][nu.se]);
                E.push_back({{nu,{i,j}}, weeee});
            }          
        }
    }

    sort(all(E), cmp);

    while(!E.empty()){
        if (cnt == 0){
            break;
        }
        iiiii e = E.back();
        E.pop_back();
        connect(e.fi.fi, e.fi.se, e.se);
    }
    int CAC = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (ans[i][j] == 1e18){
                // cout << 0 << " ";
                continue;
            }
            // cout << ans[i][j] << " ";
            CAC += ans[i][j];
        }
        // cout << endl;
    }

    

    cout << CAC;

    return 0;
}