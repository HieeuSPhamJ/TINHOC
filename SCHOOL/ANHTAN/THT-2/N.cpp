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
const int mod = 1e9 + 7;

int n, m;
vector <ii> adj[maxN];
int visited[maxN];
int permu[maxN];
int ma[maxN];
int mi[maxN];

void dickcha(){
    priority_queue <ii, vector <ii>, greater <ii>> q;
    for (int i = 1; i <= n; i++){
        visited[i] = inf;
        ma[i] = 0;
        mi[i] = inf;
    }
    q.push({0,1});
    visited[1] = 0;
    ma[1] = 0;
    mi[1] = 0;
    permu[1] = 1;
    
    while(q.size()){
        ii t = q.top();
        q.pop();
        if (visited[t.se] != t.fi){
            continue;
        }
        // cout << "With: " << t.se << endl;
        for (auto i: adj[t.se]){
            if (visited[i.se] > t.fi + i.fi){
                // cout << i.se << " ";
                visited[i.se] = t.fi + i.fi;
                ma[i.se] = ma[t.se] + 1;
                mi[i.se] = mi[t.se] + 1;
                permu[i.se] = permu[t.se];
                q.push({visited[i.se], i.se});
            }
            else if (visited[i.se] == t.fi + i.fi){
                // cout << i.se << " ";
                ma[i.se] = max(ma[i.se], ma[t.se] + 1);
                mi[i.se] = min(mi[i.se], mi[t.se] + 1);
                (permu[i.se] += permu[t.se]) %= mod;
            }
        }
        // cout << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        // adj[b].push_back({c,a});
    
    }   

    dickcha();

    if (visited[n] == inf){
        cout << -1 << endl;
        return 0;
    }

    cout << visited[n] << " " << permu[n] << " " << mi[n] << " " << ma[n] << endl;

    return 0;
}