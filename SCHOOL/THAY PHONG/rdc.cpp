#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define val first
#define id second
#define len first
#define num second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;
const int maxN = 1e3 + 10;

int n, m, k, s, t;
vector <ii> adj[maxN];
int visited[maxN][maxN];
vector <ii> E;
vector <ii> K;
priority_queue <ii, vector <ii>, greater <ii>> myHeap;

void reset(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            visited[j][i] = inf;
            visited[j][i] = inf;
        }
    }
}

void Dickcha(int type, int Start){
    
}

int cal(int a, int b){
    int temp = 0;
    for (auto i: K){
        int x = i.fi;
        int y = i.se;
        int t = visited[x][y];
        t = min(t, visited[a][x] + visited[b][y]);
        t = min(t, visited[b][x] + visited[a][y]);
        temp += t;
    }
    return temp;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    reset();
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        E.push_back({a,b});
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }
    int ans = inf;
    
    for (int i = 1; i <= k; i++){
        int a, b;
        cin >> a >> b;
        K.push_back({a,b});
    }

    for (int i = 1; i <= n; i++){
        Dickcha(i,i);
    }

    for (auto i: E){
        int a = i.fi;
        int b = i.se;
        int temp = min(cal(a,b), cal(b,a));
        ans = min(ans,temp);
    }
    cout << ans;
    return 0;
} 