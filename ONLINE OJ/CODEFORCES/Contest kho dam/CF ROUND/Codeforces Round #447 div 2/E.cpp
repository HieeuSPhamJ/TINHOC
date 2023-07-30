#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int n, m;
vector <ii> adj[maxN];
int com[maxN];
int low[maxN];
int num[maxN];
int cnt = 1;
vector <int> st;
vector <pair <ii,int>> ls;
int cost[maxN];
int dp[maxN];
int vis[maxN];
int vao[maxN];
int res = 0;

void tarjan(int nu){
    st.push_back(nu);
    low[nu] = num[nu] = cnt++;
    for (auto i: adj[nu]){
        int tnu = i.se;
        if (num[tnu]){
            low[nu] = min(low[nu], num[tnu]);
        }
        else{
            tarjan(tnu);
            low[nu] = min(low[nu], low[tnu]);
        }
    }
    // cout << nu << " " << low[nu] << " " << num[nu] << endl;
    if (low[nu] == num[nu]){
        while(st.back() != nu){
            com[st.back()] = com[nu];
            num[st.back()] = low[st.back()] = 1e18;
            st.pop_back();
        }
        com[st.back()] = com[nu];
        num[st.back()] = low[st.back()] = 1e18;
        st.pop_back();
    }
}

void init(){
    for (int i = 1; i < 1e5; i++){
        dp[i] = dp[i - 1] + (1 + i) * i / 2;
    }

    for (int i = 1; i <= n; i++){
        com[i] = i;
    }
    for (int i = 1; i <= n; i++){
        if (num[i] == 0){
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++){
        // cout << i << ": " << com[i] << endl;
        adj[i].clear();
    }
    for (auto i: ls){
        int a = i.fi.fi;
        int b = i.fi.se;
        int w = i.se;
        a = com[a];
        b = com[b];
        if (a == b){
            int k = -1;
            int l = 0;
            int r = 1e8;
            while(l <= r){
                int mid = (l + r) / 2;
                if (mid * (mid + 1) / 2 > w){
                    r = mid - 1;
                }
                else{
                    k = mid + 1;
                    l = mid + 1;
                }
            }
            cost[b] += k * w - dp[k - 1];
            // cout << w << ": " << k << " " << dp[k - 1] << " " << cost[b] << endl;
        }
    }

    for (auto i: ls){
        int a = i.fi.fi;
        int b = i.fi.se;
        int w = i.se;
        a = com[a];
        b = com[b];
        if (a == b){
            continue;
        }
        adj[a].push_back({w + cost[b],b});
        vao[b]++;
        // cout << a << " " << b << " " << cost[b] + w << endl;
    }
}



void findmin(int s){
    queue <int> q;
    deque <int> topo;
    for (int i = 1; i <= n; i++){
        vis[i] = -1;
        if (vao[i] == 0){
            q.push(i);
        }
    }
    while(q.size()){
        int t = q.front();
        q.pop();
        topo.push_back(t);
        for (auto i: adj[t]){
            vao[i.se]--;
            if (vao[i.se] == 0){
                q.push(i.se);
            }
        }
    }

    while(topo.front() != s){
        topo.pop_front();
    }
    vis[s] = cost[s];
    for (auto i: topo){
        if (vis[i] == -1){
            continue;
        }
        // cout << i << ": " << endl;;
        res = max(res,vis[i]);
        for (auto nu: adj[i]){
            // cout << nu.se << endl;
            vis[nu.se] = max(vis[nu.se], vis[i] + nu.fi);
        }
    }
    // cout << endl;
    
    for (int i = 1; i <= n; i++){
        res = max(res,vis[i]);
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
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w,b});
        ls.push_back({{a,b}, w});
    }

    init();
    int s;
    cin >> s;
    s = com[s];
    findmin(s);
    cout << res << endl;
    return 0;
}