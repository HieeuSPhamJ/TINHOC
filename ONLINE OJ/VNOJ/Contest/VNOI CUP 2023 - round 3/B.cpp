#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 110;


int n, a, b;
int vis[maxN];

int dfs(int x){
    if (x < 0 or x > n){
        return 0;
    }
    // cout << x << endl;
    if (x == 0){
        return 1;
    }
    if (vis[x] == 1){
        return 0;
    }
    vis[x] = 1;
    int res = 0;

    for (int i = 1; i <= n; i++){
        int j = a - i;
        if (x - i >= 0 and n - x - j >= 0){
            res = max(res, dfs(x - i + j));
        }
    }

    return res;
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
        cin >> n >> a >> b;
        int s[2] = {0};
        for (int i = 1; i <= n; i++){
            char x;
            cin >> x;
            s[x - '0']++;
            vis[i] = 0;
        }
        int x = s[0];
        if (b - a >= 1){
            cout << "YES" << endl;
        }
        else if (x % a == 0){
            cout << "YES" << endl;
        }
        else if (dfs(x)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}