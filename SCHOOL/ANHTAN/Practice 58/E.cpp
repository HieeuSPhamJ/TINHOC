#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define iii pair <ii,int>
using namespace std;

const int maxN = 200010;

int lmao;
vector <iii> adj[maxN];
unordered_map <int,int> visited[maxN];
priority_queue <iii, vector <iii>, greater <iii>> q;

void Dickcha(int Start){
    for (auto i: adj[Start]){
        visited[i.se][Start] = i.fi.fi;
        q.push({i.fi, i.se});
    }

    while(!q.empty()){
        auto t = q.top();
        q.pop();
        for (auto i: adj[t.se]){
            int w = t.fi.fi + i.fi.fi + lmao * t.fi.se + i.fi.se;
            if (i.se != Start and (visited[i.se][t.se] == 0 or visited[i.se][t.se] > w)){
                visited[i.se][t.se] = w;
                q.push({{w,i.fi.se}, i.se});
            }
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m,s,t;
    cin >> n >> m >> s >> t >> lmao;
    
    for (int i = 1; i <= m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({{w,i},b});
    }

    Dickcha(s);

    int ans = 1e18;

    for (int i = 1; i <= m; i++){   
        if (visited[t][i] == 0){
            continue;
        }
        ans = min(ans, visited[t][i]);
    }
    if (ans == 1e18){
        cout << -1;
        return 0;
    }
    
    cout << ans;


    return 0;
}