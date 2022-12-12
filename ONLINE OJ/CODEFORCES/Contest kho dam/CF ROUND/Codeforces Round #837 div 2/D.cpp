#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2 * 1e3 + 10;

int ans = 0;
int a[maxN];
vector <int> adj[maxN];
vector <int> leaves;
unordered_set <int> hasVisited[maxN];
vector <int> str;
int dp[maxN][maxN];
vector <vector<int>> listStr;

bool cmp(vector<int>& x, vector<int>& y){
    return x.size() > y.size();
}

void init(int i, int d){
    int ok = 1;
    for (auto j: adj[i]){
        if (j == d){
            continue;
        }
        ok = 0;
        init(j,i);
    }
    if (ok){
        leaves.push_back(i);
    }
}

int cntPalin(vector<int>& s){
    int n = s.size() - 1;

    // for (auto i: s){
    //     cout << char(i + 'a');
    // }
    // cout << endl;

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = 0;
        }
    }
    vector <int> is = s;
    reverse(all(is));

    for (int i = 0; i <= n; i++){
        dp[0][i] = dp[0][max(0ll,i - 1)];
        dp[i][0] = dp[max(0ll,i - 1)][0];
        if (s[0] == is[i]){
            dp[0][i] = 1;
        }
        if (s[i] == is[0]){
            dp[i][0] = 1;
        }
        
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i] == is[j]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    return dp[n][n];
}

bool check(int a, int b){
    if (hasVisited[b].find(a) != hasVisited[b].end()){
        return 1;
    }
    if (hasVisited[a].find(b) != hasVisited[a].end()){
        return 1;
    }
    
    return 0;
}

void Try(int node, int father, int root){
    int ok = 1;
    // cout << node << endl;
    str.push_back(a[node]);
    hasVisited[node].insert(root);

    for (auto newNode: adj[node]){
        if (newNode == father or check(newNode, root)){
            continue;
        }
        ok = 0;
        Try(newNode,node,root);
    }
    if (ok){
        listStr.push_back(str);
    }
    str.pop_back();
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
        // cout << "----TEST----" << endl;
        int n;
        cin >> n;
        ans = 0;
        leaves.clear();
        // leaves.push_back(1);
        for (int i = 1; i <= n; i++){
            char x;
            cin >> x;
            a[i] = x - 'a';
            adj[i].clear();
            hasVisited[i].clear();
        }
        for (int i = 1; i < n; i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);   
        }
        init(1,1);
        if (adj[1].size() == 1){
            leaves.push_back(1);
        }
        for (auto root: leaves){
            Try(root,root,root);
        }
        sort(all(listStr), cmp);
        for (auto& s: listStr){
            if (s.size() <= ans){
                break;
            }
            ans = max(ans, cntPalin(s));
        }
        cout << ans << endl;
    }
    return 0;
}