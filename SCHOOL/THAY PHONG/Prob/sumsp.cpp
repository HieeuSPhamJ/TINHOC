#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

struct iii{
    int a, b, w;
};

const int maxN = 2 * 1e5 + 10;

int father[maxN];
int dp[maxN];
int n, m;
int ans[(int)1e7 + 100];
vector <ii> adj[maxN];

bool cmp(iii a, iii b){
    return a.w < b.w;
}

int findFather(int child){
    if (child == father[child]){
        return child;
    }
    return father[child] = findFather(father[child]);
}

void DFS(int node, int father){
    dp[node] = 1;
    for (auto newNode: adj[node]){
        if (newNode.se == father){
            continue;
        }
        DFS(newNode.se, node);
        dp[node] += dp[newNode.se];
        ans[newNode.fi] = (n - dp[newNode.se]) * dp[newNode.se]; 
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i <= 1e7 + 10; i++){
        ans[i] = 0;
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        father[i] = i;
    }
    vector <iii> E;
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        E.push_back({a,b,w});
    }
    sort(E.begin(), E.end(), cmp);


    for (auto tempE: E){
        int a = findFather(tempE.a);
        int b = findFather(tempE.b);
        if (a == b){
            continue;
        }
        adj[tempE.a].push_back({tempE.w,tempE.b});
        adj[tempE.b].push_back({tempE.w,tempE.a});
        // cout << tempE.a << " " << tempE.b << " " << tempE.w << endl;
        father[a] = b;
    }

    DFS(1,1);
    int last = 0;
    for (int i = 0; i <= 1e7; i++){
        int t = ans[i];
        ans[i + 1] += t / 2;
        ans[i] = t % 2;
    }
    for (int i = 0; i <= 1e7; i++){
        // cout << ans[i] << " ";
        if (ans[i] != 0){
            last = i;
        }
    }
    // cout << endl;
    for (int i = last; i >= 0; i--){
        cout << ans[i];
    }

    return 0;
}