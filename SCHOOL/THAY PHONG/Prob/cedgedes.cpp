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
const int inf = 1e18;

struct node{
    int to, rev, had, cap;
};

int n, m, s, t;
vector <node> adj[maxN];
vector <ii> dadj[maxN];
int nxt[maxN];
int dist[maxN];

void add(int a, int b, int w){
    // cout << a << " " << b << " " << w << endl;
    node u = {b,(int)adj[b].size(),0,w};
    node v = {a,(int)adj[a].size(),0,0};
    adj[a].push_back(u);
    adj[b].push_back(v);
    
}

bool cango(){
    memset(dist, -1, sizeof(dist));
    queue <int> q;
    q.push(s);
    dist[s] = 0;
    int check = 0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        if (temp == t){
            check = 1;
        }
        for (auto i: adj[temp]){
            if (dist[i.to] == -1 and i.had < i.cap){
                dist[i.to] = dist[temp] + 1;
                q.push(i.to); 
            }
        }
    }

    return check;
}

int Try(int node, int Min){
    if (node == t){
        return Min;
    }
    for (auto &nu: adj[node]){
        if (dist[nu.to] == dist[node] + 1 and nu.had < nu.cap){
            int tempMin = min(Min,nu.cap - nu.had);
            tempMin = min(tempMin, Try(nu.to,tempMin));
            if (tempMin > 0){
                // cout << node << " " << nu.to << " " << tempMin << endl;
                nu.had += tempMin;
                adj[nu.to][nu.rev].had -= tempMin;
                return tempMin;
            }
        }
    }


    return 0;
}

int dinic(){
    int res = 0;
    // cango();
    // for (int i = 1; i <= n; i++){
    //     cout << dist[i] << endl;
    // }
    while(cango()){
        memset(nxt, 0, sizeof(nxt));
        // cout << "Turn" << endl;
        while(int temp = Try(s,inf)){
            res += temp;
        }
    }
    return res;
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, v, cost;
        cin >> a >> b >> v >> cost;
        dadj[a].push_back({v,b});
        dadj[b].push_back({v,a});
    }

    dickcha(1,0);
    dichcha(n,1);



    return 0;
}