#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define iii pair <ii,int>
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;

vector <int> adj[maxN];
int ans[maxN];
int check[maxN];
ii visited[maxN];

signed main(){
    freopen("RACE.INP", "r", stdin);
    freopen("RACE.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q, k;
    cin >> n >> m >> q >> k;
    queue <int> que;
    for (int i = 1; i <= n; i++){
        ans[i] = inf;
        visited[i] = {inf,inf};
    }
    for (int i = 1; i <= q; i++){
        int x;
        cin >> x;
        que.push(x);
        check[x] = 1;
        ans[x] = 0;
        visited[x] = {0,0};
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    while(!que.empty()){
        int t = que.front();
        que.pop();
        queue <int> tempQueue;
        tempQueue.push(t);
        int day = visited[t].fi;
        visited[t].se = 0;
        // cout << "With: " << t << " " << day << endl;
        while(!tempQueue.empty()){
            int tt = tempQueue.front();
            tempQueue.pop();
            if (visited[tt].se >= (day + 1) * k){
                // cout << tt << "-" << "break ";
                continue;
            }
            for (auto i: adj[tt]){
                if (visited[i].fi > day + 1){
                    check[i] = 1;
                    visited[i].fi = day + 1;
                    visited[i].se = visited[tt].se + 1;
                    que.push(i);
                    tempQueue.push(i);
                    // cout << i << " ";
                }
                if (visited[i].fi == day + 1 and visited[i].se > visited[tt].se + 1){
                    check[i] = 1;
                    visited[i].fi = day + 1;
                    visited[i].se = visited[tt].se + 1;
                    que.push(i);
                    tempQueue.push(i);
                    // cout << i << " ";
                }
            }
        }
        // cout << endl;
    }

    // for (int i = 1; i <= n; i++){
    //     cout << check[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i <= n; i++){
        cout << visited[i].fi << " ";
    }
    // cout << endl;
    return 0;
}