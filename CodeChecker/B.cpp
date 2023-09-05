#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

<<<<<<< HEAD
const int maxN = 1e3 + 10;

vector <ii> adj[maxN];
int co[maxN][maxN];
ii cap[maxN][maxN];
int vis[maxN];

void dickcha(int S, int G){
    for (int i = 1; i < maxN; i++){
        vis[i] = 1e18;
    }
    priority_queue <ii,vector<ii>,greater<ii>> q;
    vis[S] = G;
    q.push({vis[S],S});
    while(q.size()){
        ii t = q.top();
        q.pop();
        if (t.fi != vis[t.se]){
            continue;
        }
        int st = t.fi;
        // cout << "With: " << t.se << " "  << st << endl;
        for (auto i: adj[t.se]){
            int et = st + i.fi;
            int nu = i.se;
            ii ca = cap[t.se][nu];
            if (ca.fi <= st and st <= ca.se){
                et = ca.se + 1 + i.fi;
            }
            if (ca.fi <= et and et <= ca.se){
                et = ca.se + 1 + i.fi;
            }
            // cout << nu << " " << et << " " << ca.fi << " " << ca.se << endl;
            if (et < vis[nu]){
                vis[nu] = et;
                q.push({vis[nu], nu});
            }
            
        }
        // cout << endl;
    }
}

signed main(){
	freopen("input.inp", "r", stdin);
	freopen("B.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int A,B,G,K;
    cin >> A >> B >> G >> K;
    vector <int> ls;
    for (int i = 1; i <= K; i++){
        int x;
        cin >> x;
        ls.push_back(x);
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cap[i][j] = {-1,-1};
        }
    }
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        co[a][b] = w;
        co[b][a] = w;
        adj[a].push_back({w,b});
        adj[b].push_back({w,a});
    }
    for (int i = 1, la = 0; i < K; i++){
        int a = ls[i - 1];
        int b = ls[i];
        cap[a][b].fi = la;
        la = la + co[a][b];
        cap[a][b].se = la - 1;
        cap[b][a] = cap[a][b];
        // cout << a << " " << b << ": " << cap[a][b].fi << " " << cap[a][b].se << endl;
    }
    dickcha(A,G);

    // for (int i = 1; i <= n; i++){
    //     cout << i << ": " << vis[i] << endl;
    // }
    
    cout << vis[B] - G << endl;

=======
signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << n << endl;
>>>>>>> 504a6cc3a59da46aa77138bf91bb5be96c0834ff
    return 0;
}