#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5e5 + 10;

int vis[maxN];
vector <int> adj[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int m;
    cin >> m;
    int k1, k2;
    cin >> k1 >> k2;
    vector <int> lsa;
    for (int i = 1; i <= k1; i++){
        int x;
        cin >> x;
        lsa.push_back(x);
    }
    vector <int> lsb;
    for (int i = 1; i <= k2; i++){
        int x;
        cin >> x;
        lsb.push_back(x);
    }

    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue <int> q;

    for (int i = 1; i <= n; i++){
        vis[i] = 1e18;
    }
    
    for (auto i: lsa){
        q.push(i);
        vis[i] = 0;
    }

    while(!q.empty()){
        int t = q.front();
        q.pop();
        for (auto i: adj[t]){
            if (vis[i] == 1e18){
                vis[i] = vis[t] + 1;
                q.push(i);
            }
        }
    }

    for (auto i: lsb){
        cout << vis[i] << " ";
    }
    cout << endl;
    return 0;
}