#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
bool isKhop[maxN];
int num[maxN];
int low[maxN];
int khop;
int cau;
int cnt;

void tarjan(int nu, int fa){
    cnt++;
    num[nu] = low[nu] = cnt;
    int child = (nu != fa);
    for (auto i: adj[nu]){
        if (i == fa){
            continue;
        }
        if (num[i]){
            low[nu] = min(low[nu], num[i]);
        }
        else{
            tarjan(i, nu);
            low[nu] = min(low[nu], low[i]);
            if (low[i] >= num[nu]){
                child++;
            }
            if (num[i] == low[i]){
                cau++;
            }
        }
    }
    if (child >= 2){
        khop++;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++){
        if (!num[i]){
            tarjan(i,i);
        }
    }

    // for (int i = 1; i <= n; i++){
    //     khop += isKhop[i];
    // }

    cout << khop << " " << cau << endl;
    return 0;
}
