#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define iii pair<int,ii>
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1010;
const int inf = 1e18;

int n, m, sx, sy, tx, ty;
int k;
vector <int> lists[maxN];
ii dd[] = {
    {0,1},
    {1,0},
    {-1,0},
    {0,-1}
};

int grid[maxN][maxN];
int vis[maxN][maxN];

int cal(ii a, ii b){
    // cout << a.fi << " " << a.se << " " << b.fi << " " << b.se << endl;
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}

bool checkIn(ii nu){
    if (grid[nu.fi][nu.se]){
        return 0;
    }
    if (nu.fi < 1 or nu.fi > n){
        return 0;
    }
    if (nu.se < 1 or nu.se > m){
        return 0;
    }
    return 1;
}

int getx(int x, int y, int d, int i){
    if (i < 1 or i > n or lists[i].empty()){
        return 1e8;
    }
    // cout << "At: " << i << endl;

    int nd = d - (x - i) * (x - i);
    int l = -1;
    int r = -1;
    int left = 0;
    int right = lists[i].size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (lists[i][mid] <= y){
            l = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    left = 0;
    right = lists[i].size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if (lists[i][mid] >= y){
            r = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    // cout << l << " " << r << endl;
    if (l == -1 and r == -1){
        return 1e8;
    }
    if (l == -1){
        l = r;
    }
    if (r == -1){
        r = l;
    }
    for (int j = l; j <= r; j++){
        // cout << lists[i][j] << " ";
        d = min(d, cal({x,y},{i,lists[i][j]}));
    }
    // cout << endl;
    return d;
}

int calmin(int x, int y, int oldlen){
    int d = oldlen;
    for (int i = 0; i * i <= d; i++){
        d = min(d,getx(x,y,d,x - i));
        d = min(d,getx(x,y,d,x + i));
    }
    return d;
}

signed main(){
    // freopen("input.inp", "r", stdin);
    // freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> sx >> sy >> tx >> ty;
    cin >> k;
    int fv = 1e18;
    for (int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
        lists[x].push_back(y);
        fv = min(fv, cal({x,y},{sx,sy}));
    }

    priority_queue <iii> q;
    q.push({fv,{sx,sy}});
    vis[sx][sy] = fv;

    for (int i = 1; i <= n; i++){
        if (!lists[i].empty()){
            sort(all(lists[i]));
        }
    }

    while(!q.empty()){ 
        iii t = q.top();
        q.pop();
        // cout << "With: " << t.se.fi << " " << t.se.se << " " << t.fi << endl;
        if (vis[t.se.fi][t.se.se] != t.fi){
            continue;
        }
        for (int ix = 0; ix < 4; ix++){
            ii nu = t.se;
            nu.fi += dd[ix].fi;
            nu.se += dd[ix].se;
            if (checkIn(nu)){
                int len = calmin(nu.fi, nu.se, t.fi);
                // cout << nu.fi << " " << nu.se << " " << len <<endl;
                if (len > vis[nu.fi][nu.se]){
                    // cout << "***" << endl;
                    vis[nu.fi][nu.se] = len;
                    q.push({len,nu});
                }
            }
        }
    }

    // cout << calmin(3,4,2) << endl;

    cout << vis[tx][ty];


    return 0;
} 