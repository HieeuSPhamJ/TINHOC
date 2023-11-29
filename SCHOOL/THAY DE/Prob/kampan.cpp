#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 210;

int n, m;
int Start = 1;
int End = 2;
int ans = 1e18;

vector <int> adj[maxN];
int visited[maxN];
int invisited[maxN];

int rev(int x){
    return x + n;
}
int inrev(int x){
    return x - n;
}

void inbacktrack(int node, int low){
    // cout << "Down: " << node << " " << low << endl;
    if (low >= ans){
        return;
    }
    int check = 0;
    if (visited[node] == 0){
        check = 1;
    }
    invisited[node] = 1;    
    if (check){
        visited[node] = 1;
        low++;
    }   

    if (node == Start){
        ans = min(ans, low);
    }
    else{
        for (auto i: adj[node]){
            if (invisited[i]){
                continue;
            }
            inbacktrack(i,low);
        }
    }
    invisited[node] = 0;
    if (check){
        visited[node] = 0;
    }
}

void backtrack(int node, int low){
    // cout << "For: " << node << " " << low << endl;
    if (low >= ans){
        return;
    }
    int check = 0;
    if (visited[node] == 0){
        check = 1;
    }

    if (check){
        visited[node] = 1;
        low++;
    }   

    if (node == End){
        inbacktrack(End, low);
    }
    else{
        for (auto i: adj[node]){
            if (visited[i]){
                continue;
            }
            backtrack(i,low);
        }
    }
    if (check){
        visited[node] = 0;
    }


}



signed main(){
    freopen("kampan.INP", "r", stdin);
    freopen("kampan.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    backtrack(Start, 0);
    cout << ans << endl;

    return 0;
}