#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

vector <ii> adj[maxN];
int fromA[maxN];
int fromB[maxN];
set <int> A;
set <int> B;
int n, x, y;

void dfs1(int node, int father){
    // if (node != father and node != y){
    //     A.insert(fromA[node]);
    // }
    if (node == y){
        return;
    }
    for (auto newNode: adj[node]){
        if (newNode.se == father){
            continue;
        }
        fromA[newNode.se] = fromA[node] xor newNode.fi;
        dfs1(newNode.se, node);
    }
}

void dfs2(int node, int father){
    // if (node != father and node != x){
    //     B.insert(fromB[node]);
    // }
    for (auto newNode: adj[node]){
        if (newNode.se == father){
            continue;
        }
        fromB[newNode.se] = fromB[node] xor newNode.fi;
        dfs2(newNode.se, node);
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
        A.clear();
        B.clear();
        cin >> n >> x >> y;
        for (int i = 1; i <= n; i++){
            adj[i].clear();
            fromA[i] = fromB[i] = -1;
        }
        fromA[x] = 0;
        fromB[y] = 0;
        for (int i = 1; i < n; i++){
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({w,b});
            adj[b].push_back({w,a});
        }

        if (n == 1 or x == y){
            cout << "YES" << endl;
            continue;
        }
        if (n == 2){
            cout << "NO" << endl;
            continue;
        }
        
        // cout << x << " " << y << endl;
        dfs1(x,x);
        dfs2(y,y);  

        A.insert(0);

        for (int i = 1; i <= n; i++){
            if (i == x or i == y){
                continue;
            }
            if (fromA[i] != -1){
                A.insert(fromA[i]);
            }
            if (fromB[i] != -1){
                B.insert(fromB[i]);
            }
            
            // cout << i << ": " << fromA[i] << " " << fromB[i] << endl;
        }

        int check = 0;
        for (auto i: A){
            if (B.find(i) != B.end()){
                check = 1;
            }
        }

        // for (auto i: A){
        //     cout << i << " ";
        // }
        // cout << endl;
        // for (auto i: B){
        //     cout << i << " ";
        // }
        // cout << endl;

        if (check == 1){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}