#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e3 + 10;

int n, m;

vector <int> adj[maxN];
int rt[maxN];
int visited[maxN];
int path[maxN];

int find(int u){
    if (u == rt[u]){
        return u;
    }
    return rt[u] = find(rt[u]);
}

ii bfs(int start){
    queue <int> myQueue;
    for (int i = 1; i <= n; i++){
        visited[i] = -1;
    }
    visited[start] = 1;
    path[start] = 0;
    myQueue.push(start);
    while(!myQueue.empty()){
        int tempV = myQueue.front();
        myQueue.pop();
        for (auto i: adj[tempV]){
            if (visited[i] == -1){
                visited[i] = visited[tempV] + 1;
                path[i] = tempV;
                myQueue.push(i);
            }
        }
    } 
    
    int ans = 0;
    int tempVal = 0;
    for (int i = 1; i <= n; i++){
        // cout << i << ": " << visited[i] << endl;
        if (tempVal <= visited[i]){
            ans = i;
            tempVal = visited[i];
        }
    }

    return {ans, tempVal};
}

ii findm(int u){
    ii x = bfs(u);
    x = bfs(x.fi);
    int t = x.fi;
    int len = x.se;
    // cout << t << " " << len << endl;
    while (visited[path[t]] * 2 >= len){
        t = path[t];
    }
    return {t,len};
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector <ii> ls;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ls.push_back({a,b});
    }

    for (int i = 1; i <= n; i++){
        rt[i] = i;
    }

    for (auto i: ls){
        int u = find(i.fi);
        int v = find(i.se);
        if (u == v){
            continue;
        }
        rt[u] = v;
    }
    priority_queue <ii> q;   
    set <int> s;
    for (int i = 1; i <= n; i++){
        s.insert(find(i));
    }
    for(auto i: s){
        q.push({findm(i).se, find(i)});
    }

    int root = q.top().se;
    q.pop();
    ls.clear();

    while(q.size()){
        ii i = q.top();
        q.pop();
        // cout << i.fi << " " << i.se << endl;
        int mi1 = findm(root).fi;
        int mi2 = findm(i.se).fi;
        // cout << mi1 << " " << mi2 << endl;
        ls.push_back({mi1,mi2});
        adj[mi1].push_back(mi2);
        adj[mi2].push_back(mi1);
    }
    // cout << endl;

    cout << findm(1).se - 1 << endl;

    for (auto i: ls){
        cout << i.fi << " " << i.se << endl;
    }

    // cout << "=END=" << endl;
    return 0;
}