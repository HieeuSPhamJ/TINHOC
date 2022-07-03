#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int maxN = 1e3 + 10;

bool check[maxN][maxN];
vector <int> banList;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        check[x][y] = 1;
        banList.push_back({x,y});
    }

    ll ans = 0;

    for (int r = 1; r <= min(n, m); r++){
        ans += r * (n - r) * (m - r);
    }

    for (int i = 1; i <= n; i++){
        
    }

    cout << ans;

    


    return 0;
}