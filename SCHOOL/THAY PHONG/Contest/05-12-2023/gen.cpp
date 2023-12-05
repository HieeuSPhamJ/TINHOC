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

const int maxN = 4010;

int n[2];
int m[2];
int dist[2][maxN];
vector <int> adj[2][maxN];
int pre[2][maxN];

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
    for (int t = 0; t <= 1; t++){
        cin >> n[t] >> m[t];
        for (int i = 1; i <= m[t]; i++){
            int a, b;
            cin >> a >> b;
            adj[t][a].push_back(b);
            adj[t][b].push_back(a);
        }
        memset(dist[t], -1, sizeof(dist[t]));
        queue <int> q;
        dist[t][1] = 0;
        q.push(1);
        while(q.size()){
            int te = q.front();
            q.pop();
            for (auto i: adj[t][te]){
                if (dist[t][i] == -1){
                    dist[t][i] = dist[t][te] + 1;
                    q.push(i);
                }
            }
        }
    }
    int res = 0;
    int dup = 0;
    for (int t = 0; t <= 1; t++){
        // cout << "With: " << t << endl;
        for (int i = 0; i <= n[!t]; i++){
            pre[0][i] = 0;
            pre[1][i] = 0;
        }
        for (int i = 1; i <= n[!t]; i++){
            int x = dist[!t][i];
            pre[x % 2][x]++;
            // cout << x << " ";
        }
        // cout << endl;
        for (int i = 1; i <= n[!t]; i++){
            pre[0][i] += pre[0][i - 1];
            pre[1][i] += pre[1][i - 1];
        }
        // cout << "=====" << endl;
        for (int i = 1; i <= n[t]; i++){
            int x = dist[t][i];
            dup += (pre[x % 2][x] - pre[x % 2][x - 1]) * x;
            // cout << x << " = " << pre[x % 2][x] - pre[x % 2][x - 1] << endl;
            if (x > 0){
                int t = pre[x % 2][x - 1];
                res += t * x;
                // cout << x << ' ' << t << endl;
            }
        }
    }
    cout << res + dup / 2;
    return 0;
}

/*
1: 1

1: 1
2: 1

1: 2
*/