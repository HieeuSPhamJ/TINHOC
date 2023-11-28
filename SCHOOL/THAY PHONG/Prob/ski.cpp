#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 510;

int n, m, t;

ii dir[]{
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};

int res[maxN][maxN];
int h[maxN][maxN];
vector <pair<int,pair<ii,ii>>> listE;

bool checkin(ii x){
    if (x.fi <= 0 or x.se <= 0){
        return 0;
    }
    if (x.fi > n or x.se > m){
        return 0;
    }
    return 1;
}

bool cmp(pair<int,pair<ii,ii>> a, pair<int,pair<ii,ii>> b){
    return a.fi < b.fi;
}

ii root[maxN][maxN];
int incon[maxN][maxN];
int sicon[maxN][maxN];

ii checkRoot(ii bf){
    if (root[bf.fi][bf.se]==bf){
        return bf;
    }
    return (root[bf.fi][bf.se]=checkRoot(root[bf.fi][bf.se]));
}

void print(ii a, char x){
    cout << a.fi << "," << a.se << " " << x;
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> t;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            root[i][j] = {i,j};
            cin >> h[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int d = 0; d < 4; d++){
                ii nu = {i,j};
                nu.fi += dir[d].fi;
                nu.se += dir[d].se;
                if (checkin(nu)){
                    listE.push_back({abs(h[i][j] - h[nu.fi][nu.se]), {{i,j},nu}});
                }
            }
        }
    }

    sort(all(listE), cmp);

    // for (auto i: listE){
    //     cout << i.fi << " " << i.se.fi.fi << " " << i.se.fi.se << " " << i.se.se.fi << " " << i.se.se.se << endl;
    // }

    vector <ii> lists;


    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int x;
            cin >> x;
            res[i][j] = -1;
            sicon[i][j] = 1;
            if (x){
                incon[i][j] = 1;
                lists.push_back({i,j});
            }
        }
    }

    int ans = 0;

    for (auto e: listE){
        int cost = e.fi;
        ii a = e.se.fi;
        ii b = e.se.se;


        ii af = checkRoot(a);
        ii bf = checkRoot(b);
        if (af == bf){
            continue;
        }
        // cout << cost << ": "; print(a,' '); print(b,endl);

        // print(af,' '); print(bf,endl);

        root[bf.fi][bf.se] = af;

        incon[af.fi][af.se] += incon[bf.fi][bf.se];
        incon[bf.fi][bf.se] = 0;

        sicon[af.fi][af.se] += sicon[bf.fi][bf.se];
        sicon[bf.fi][bf.se] = 0;

        // cout << sicon[af.fi][af.se] << " " << sicon[bf.fi][bf.se] << endl;

        // for (int i = 1; i <= n; i++){
        //     for (int j = 1; j <= m; j++){
        //         cout << sicon[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        if (sicon[af.fi][af.se] >= t){
            // cout << "OK" << endl;
            // cout << incon[af.fi][af.se] << " " << cost << endl;
            ans += incon[af.fi][af.se] * cost;
            incon[af.fi][af.se] = 0;
        }
        // cout << endl;
    }
    

    cout << ans << endl;
    return 0;
}