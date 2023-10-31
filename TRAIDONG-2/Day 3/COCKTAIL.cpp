#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

vector <int> adj[maxN];
int cnt[maxN];
int co[maxN];
int a[maxN];

int dp[maxN];
int ans[maxN];
int dp[maxN]

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("COCKTAIL.inp", "r")) {
        freopen("COCKTAIL.inp", "r", stdin);
        freopen("COCKTAIL.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> co[i];
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    int st = -1;
    for (int i = 1; i <= n; i++){
        if (cnt[i] == 1){
            st = i;
        }
    }
    // cout << st << endl;
    vector <int> ls;
    ls.push_back(st);
    cnt[st] = 0;
    while(1){
        int ok = 1;
        for (auto i: adj[st]){
            if (cnt[i] == 0){
                continue;
            }
            ok = 0;
            cnt[i] = 0;
            st = i;
            ls.push_back(st);
        }
        if (ok){
            break;
        }
    }
    for (int i = 0; i < n; i++){
        a[i + 1] = co[ls[i]];
        cout << a[i + 1] << " ";
    }
    cout << endl;
    int test;
    cin >> test;

    while(test--){
        int k;
        cin >> k;
        cout << ans[k] << endl;
    }

    return 0;
}