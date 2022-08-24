#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, k;

vector <int> adj[maxN];
int dp[maxN][510];
int ans = 0;
int root = 1;

void DFS(int node, int father){
	for (auto newNode : adj[node]){
		if (newNode == father){
            continue;
		}
		DFS(newNode, node);
		for (int i = 1; i <= k; i++){
			ans += dp[node][k - i] * dp[newNode][i - 1];
        }
        for (int i = 1; i <= k; i++){
			dp[node][i] += dp[newNode][i - 1];
        }
	}
}

void init(){
    for (int i = 1; i <= n; i++){
        dp[i][0] = 1;
    }
}

bool checkLine(){
    if (n == 1){
        return 1;
    }
    int count = 0;
    for(int i = 1; i <= n; i++){
        if (adj[i].size() == 2){
            count++;
        }
        else if (adj[i].size() == 1){
            root = i;
        }
    }
    if (count == n - 2){
        return 1;
    }
    return 0;
}

void sub3(){
    int ans = 0;
    for (int i = 1; i + k <= n; i++){
        ans += 1;
    }
    cout << ans << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init();

    if (checkLine()){
        // cout << "SNAKE GRAPH GO BURBURB: " << root << endl;
        sub3();
        return 0;
    }

    DFS(1,1);

    cout << ans;

    return 0;
}