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
int cost[1010][1010];
int had[1010][1010];
int cap[1010][1010];
vector <int> adj[1010];
int dist[1010];
int trace[1010];
int N;

void add(int a, int b, int costi, int capa){
    cost[a][b] = cost[b][a] = costi;
    cap[a][b] = cap[b][a] = capa;

    adj[a].push_back(b);
    adj[b].push_back(a);

}

bool cango(){
    for (int i = 1; i <= n; i++){
        dist[i] = inf;
        trace[i] = 0;
    }

    queue <int> q;
    q.push(s);
    dist[s] = 0;

    while(q.empty() == 0){
        int te = q.front();
        q.pop();
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
                q.push(i);
                trace[i] = te;
            }
        }
    }
    return dist[t] != inf;
}

vector <int> st;

void findPath(int i){
    st.push_back(i);
    if (i == s){
        return;
    }
    for (auto nu: adj[i]){
        if (had[nu][i] == 1){
            had[nu][i] = 2;
            findPath(nu);
            return;
        }
    }
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
        for (int i = 1; i <= N; i++){
            st.clear();
            findPath(t);
            cout << st.size() << " ";
            for (int i = (int)st.size() - 1; i >= 0; i--){
                cout << st[i] << " ";
            }
            cout << endl; 
        }
        exit(0);
    }
}


void minCost(){
    while(cango()){
        Try();
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> VAL >> s >> t;
    N = VAL;
    for (int i = 1; i <= m; i++){
        int a, b, costi, capa;
        cin >> a >> b >> costi;
        capa = 1;
        add(a,b,costi,capa);
    }

    minCost();

    cout << -1 << endl;
    return 0;
}