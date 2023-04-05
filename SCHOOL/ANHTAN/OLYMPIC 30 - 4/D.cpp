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
// int cost[1010][1010];
// int had[1010][1010];
// int cap[1010][1010];
vector <int> adj[100010];
int dist[100010];
int trace[100010];


unordered_map <int,unordered_map<int,int>> cost;
unordered_map <int,unordered_map<int,int>> had;
unordered_map <int,unordered_map<int,int>> cap;


void add(int a, int b, int capa, int costi){
    // cout << a << " " << b << " " << costi << endl;
    cost[a][b] = cost[b][a] = costi;
    cap[a][b] = capa;

    adj[a].push_back(b);
    adj[b].push_back(a);

}

bool cango(){
    for (int i = 0; i <= 2 * n * m; i++){
        dist[i] = inf;
        trace[i] = 0;
    }

    queue <int> q;
    q.push(s);
    dist[s] = 0;
    // cout << "TRYYYYYYYYYYYYYYYY" << endl;
    while(q.size()){
        int te = q.front();
        q.pop();
        // cout << "With: " << te << endl;
        for (auto i: adj[te]){
            if (had[te][i] >= cap[te][i]){
                continue;
            }
            int co = cost[te][i];
            if (had[te][i] < 0){
                co = -co;
            }

            if (dist[i] > dist[te] + co){
                // cout << i << " ";
                dist[i] = dist[te] + co;
                q.push(i);
                trace[i] = te;
            }
        }
            // cout << endl;
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
    // cout << now << " " << -ans << endl;
    if (!VAL){
        cout << -ans << endl;
        exit(0);
    }
}

void minCost(){
    int lim = 1;
    while(cango()){
        Try();
        if (lim >= 2){
            break;
        }
        lim++;
    }
}

int conv(int i, int j){
    return (i - 1) * m + j;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int x;
            cin >> x;
            add(conv(i,j), conv(i,j) + n * m, 1, -x);
            if (i > 1){
                add(conv(i - 1, j) + n * m, conv(i, j), 1, 0);
            }
            if (j > 1){
                add(conv(i, j - 1) + n * m, conv(i, j), 1, 0);
            }
        }
    }

    VAL = 2;
    s = 1 + n * m;
    t = n * m;
    minCost();

    return 0;
}