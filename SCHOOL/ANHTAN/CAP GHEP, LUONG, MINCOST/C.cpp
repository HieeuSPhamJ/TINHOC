#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int inf = 1e18;

int ans = 0;
int n, m, VAL, s, t;
int cost[420][420];
int had[420][420];
int cap[420][420];
vector <int> adj[420];
int dist[420];
int trace[420];
int inq[420];

void add(int a, int b, int costi, int capa){
    // cout << a << " " << b << " " << capa << endl;
    cost[a][b] = cost[b][a] = costi;
    cap[a][b] = capa;

    adj[a].push_back(b);
    adj[b].push_back(a);

}

int hasAns;

bool cango(){
    for (int i = 0; i <= n + m + 1; i++){
        dist[i] = inf;
        trace[i] = 0;
    }

    queue <int> q;
    q.push(s);
    dist[s] = 0;
    inq[s] = 1;

    while(q.empty() == 0){
        int te = q.front();
        q.pop();
        inq[te] = 0;
        for (auto i: adj[te]){
            if (had[te][i] >= cap[te][i]){
                continue;
            }
            int co = cost[te][i];
            if (had[te][i] < 0){
                co = -co;
            }

            if (dist[i] > dist[te] + co){
                dist[i] = dist[te] + co;
                trace[i] = te;
                if (inq[i] == 0){
                    q.push(i);
                    inq[i] = 1;
                }
            }
        }
    }
    return dist[t] != inf;
}


void Try(){
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
        hasAns = 1;
        return;
    }
}


void minCost(){
    hasAns = 0;
    ans = 0;
    while(cango()){
        Try();
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
    int test;
    cin >> test;
    while(test--){
        cin >> n >> m;

        s = 0;
        t = n + m + 1;
        VAL = 0;

        memset(cost,0,sizeof(cost));
        memset(had,0,sizeof(had));
        memset(cap,0,sizeof(cap));
        
        for (int i = 0; i <= t; i++){
            adj[i].clear();
        }

        for (int i = 1; i <= n; i++){
            int w;
            cin >> w;
            add(s,i,0,w);
        }

        for (int i = 1; i <= m; i++){
            int w;
            cin >> w;
            add(i + n,t,0,w);
            VAL += w;
        }


        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                int w;
                cin >> w;
                add(i,j + n,w,inf);
            }
        }
        minCost();
    }
    return 0;
}