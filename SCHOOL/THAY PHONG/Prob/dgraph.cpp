#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
int vis[maxN];
int vao[maxN];
vector <int> sto[maxN];
int res[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        vao[b]++;
    }

    queue <int> q;
    for (int i = 1; i <= n; i++){
        if (vao[i] == 0){
            q.push(i);
            vis[i] = 1;
        }
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        for (auto i: adj[t]){
            vao[i]--;
            if (vao[i] == 0){
                vis[i] = vis[t] + 1;
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        sto[vis[i]].push_back(i);
    }
    for (int i = 1, cnt = 1; i <= n; i++){
        if (sto[i].size()){
            sort(all(sto[i]));
            for (int x: sto[i]){
                res[x] = cnt;
                cnt++;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}