#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int inf = 1e18;

struct node{
    int to, rev, had, cap;
};

int n, m, s, t;
vector <node> adj[maxN];
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
    for (auto& nu: adj[node]){
        if (dist[nu.to] == dist[node] + 1 and nu.had < nu.cap){
            int tMin = min(Min,nu.cap - nu.had);
            tMin = Try(nu.to, tMin);
            if (tMin != 0){
                nu.had += tMin;
                adj[nu.to][nu.rev].had -= tMin;
                return tMin;
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
        while(int temp = Try(s,inf)){
            res += temp;
        }
    }
    return res;
}

vector <int> lists[4][maxN];
ii a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    s = 0;
    t = n + n + m + m + 1;

    int lay1 = 0;
    int lay2 = n;
    int lay3 = lay2 + m;
    int lay4 = lay3 + m;
    
    string str;
    getline(cin, str);
    for (int i = 1; i <= n; i++){
        add(s,lay1 + i,1);
        
        getline(cin, str);
        stringstream ss;
        ss << str;
        int x;
        
        while(ss >> x){
            // lists[1][i].push_back(x);
            add(i,lay2 + x,1);
            // cout << x << " ";
        }
        // cout << endl;
    }

    for (int i = 1; i <= n; i++){
        add(lay4 + i, t, 1);
        getline(cin, str);
        stringstream ss;
        ss << str;
        int x;
        while(ss >> x){
            add(lay3 + x, lay4 + i,1);
            
            // cout << x << " ";
            // lists[2][i].push_back(x);
        }
        
        // cout << endl;
    }

    for (int i = 1; i <= m; i++){
        add(lay2 + i, lay3 + i, 1);
        
    }

    int t = dinic();

    // cout << t << endl;

    for (int i = 1; i <= n; i++){
        for (auto e: adj[i]){
            // cout << i << " " << e.to << " " << e.had << endl;
            if (e.had > 0 and e.to >= 1){
                a[e.to - n].fi = i;
                break;
            }
        }
    }

    for (int i = 1; i <= m; i++){
        for (auto e: adj[i + n + m]){
            if (e.had > 0 and e.to > lay4){
                a[i].se = e.to - lay4;
                break;
            }
        }
    }

    for (int i = 1; i <= m; i++){
        cout << a[i].fi << " " << a[i].se << endl;
    }


    return 0;
}