#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1010 + 10;
const int inf = 1e18;

struct node{
    int to, rev, had, cap;
};

int n, m, s, t;
vector <node> adjFlow[maxN];
vector <int> adjMin[maxN];
int nxt[maxN];
int dist[maxN];
int cost[maxN][maxN];
int had[maxN][maxN];
int cap[maxN][maxN];
int trace[maxN];
int VAL;
int ans;

void add(int a, int b, int c, int w){
    // cout << a << " " << b << " " << w << endl;
    node u = {b,(int)adjFlow[b].size(),0,w};
    node v = {a,(int)adjFlow[a].size(),0,0};
    adjFlow[a].push_back(u);
    adjFlow[b].push_back(v);
    cost[a][b] = cost[b][a] = c;
    cap[a][b] = w;
    adjMin[a].push_back(b);
    adjMin[b].push_back(a);
}

bool cangoDinic(){
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
        for (auto i: adjFlow[temp]){
            if (dist[i.to] == -1 and i.had < i.cap){
                dist[i.to] = dist[temp] + 1;
                q.push(i.to); 
            }
        }
    }

    return check;
}

int tryDinic(int node, int Min){
    if (node == t){
        return Min;
    }
    for (auto &nu: adjFlow[node]){
        if (dist[nu.to] == dist[node] + 1 and nu.had < nu.cap){
            int tempMin = min(Min,nu.cap - nu.had);
            tempMin = min(tempMin, tryDinic(nu.to,tempMin));
            if (tempMin > 0){
                // cout << node << " " << nu.to << " " << tempMin << endl;
                nu.had += tempMin;
                adjFlow[nu.to][nu.rev].had -= tempMin;
                return tempMin;
            }
        }
    }


    return 0;
}

int dinic(){
    int res = 0;
    // cangoDinic();
    // for (int i = 1; i <= n; i++){
    //     cout << dist[i] << endl;
    // }
    while(cangoDinic()){
        memset(nxt, 0, sizeof(nxt));
        // cout << "Turn" << endl;
        while(int temp = tryDinic(s,inf)){
            res += temp;
        }
    }
    return res;
}


bool cangoMin(){
    for (int i = 0; i <= n + n + 1; i++){
        dist[i] = inf;
        trace[i] = 0;
    }

    queue <int> q;
    q.push(s);
    dist[s] = 0;

    while(q.empty() == 0){
        int te = q.front();
        q.pop();
        for (auto i: adjMin[te]){
            if (had[te][i] >= cap[te][i]){
                continue;
            }
            int co = cost[te][i];
            if (had[te][i] < 0){
                co = -co;
            }

            if (dist[i] > dist[te] + co){
                dist[i] = dist[te] + co;
                q.push(i);
                trace[i] = te;
            }
        }
    }
    return dist[t] != inf;
}

int hasAns;

void tryMin(){
    int now = inf;
    for (int i = t; i != s; i = trace[i]){
        int temp = -had[trace[i]][i];
        if (had[trace[i]][i] >= 0){
            temp = cap[trace[i]][i] - had[trace[i]][i];
        }
        now = min(now, temp);
        
    }

    now = min(now, VAL);

    for (int i = t; i != s; i = trace[i]){
        had[i][trace[i]] -= now;
        had[trace[i]][i] += now;
    }
    VAL -= now;
    ans += now * dist[t];
    if (!VAL){
        cout << ans << endl;
        for (int i = 1; i <= n; i++){
            for (int j = n + 1; j <= n + n; j++){
                if (had[i][j] > 0)
                cout << i << " " << j - n << endl;
            }
        }
        return;
    }
}


void minCost(){
    hasAns = 0;
    while(cangoMin()){
        tryMin();
        if (hasAns){
            return;
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int a, b, w;
    s = 0;
    t = n + n + 1;
    for (int i = 1; i <= n; i++){
        add(s,i,0,1);
        add(i + n,t,0,1);
    }

    while(cin >> a >> b >> w){
        add(a,b + n,w,1);
    }
    VAL = dinic();

    minCost();
    // cout << VAL << endl;
    return 0;
}