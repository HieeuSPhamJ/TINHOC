#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2000 + 10;
const int inf = 1e9;

struct node{
    int to, rev, had, cap;
};
int n, m, s, t;
vector <node> adjFlow[maxN];
vector <int> adjMin[maxN];
// unordered_map <int,int> nxt;
// unordered_map <int,int> dist;
// unordered_map <int,unordered_map <int,int>> cost;
// unordered_map <int,unordered_map <int,int>> had;
// unordered_map <int,unordered_map <int,int>> cap;
// unordered_map <int,int> trace;
int nxt[maxN];
int dist[maxN];
int cost[maxN][maxN];
int had[maxN][maxN];
int cap[maxN][maxN];
int trace[maxN];
int VAL;
int ans;
int maxNode = 0;

void add(int a, int b, int c, int w){
    // cout << a << " " << b << " " << c << endl;
    // cout << a << " " << b << " " << c << " " << w << endl;
    maxNode = max(maxNode, max(a,b));
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
    for (int i = 0; i <= maxNode; i++){
        dist[i] = inf;
        trace[i] = 0;
    }

    queue <int> q;
    q.push(s);
    dist[s] = 0;

    while(q.empty() == 0){
        int te = q.front();
        q.pop();
        // cout << "Node: " << te << endl;
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
    // cout << "Dist:" << dist[t] << endl;
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
        exit(0);
    }
}


void minCost(){
    hasAns = 0;
    while(cangoMin()){
        // cout << "turn" << endl;
        tryMin();
    }
    cout << "-1" << endl;
}

int c[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    s = 0;
    int lay1 = 0;
    int lay2 = n;
    for (int i = 1; i <= n; i++){
        string ss;
        cin >> ss;
        m = ss.size();
        for (int j = 1; j <= m; j++){
            char x = ss[j - 1];
            if (x == 'Y'){
                add(i,j + n,0,1);
            }
        }
        t = n + ss.size() + 1;
    }

    for (int i = 1; i <= m; i++){
        add(i + n,t,0,1);
    }

    int layTemp = n + m + n;

    int layCost = n + m + n + n;

    for (int i = 1; i <= n; i++){
        add(s,layTemp + i,0,inf);
        for (int j = 1; j <= m; j++){
            int costNode = layCost + m * (i - 1) + j;
            add(layTemp + i, costNode,c[i] * (j * j - (j - 1) * (j - 1)),1);
            add(costNode, lay1 + i,0,inf);
        }
    }

    VAL = dinic();
    if (VAL == m){
        minCost();
    }
    cout << -1;
    // cout << "Final:" << VAL << " " << s << " " << t << endl;

    return 0;
}

/*
*/