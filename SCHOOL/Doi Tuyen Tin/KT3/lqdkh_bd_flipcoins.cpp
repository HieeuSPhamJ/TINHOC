#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int n = 4;
bool a[6][6];
int ans = 1e18;
int temp = 0;
ii d[]{
    {0,0},
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

int at(int i, int j){
    return a[i][j] + a[i][j - 1] + a[i - 1][j] + a[i + 1][j] + a[i][j + 1];
}

void flip(int i, int j){
    for (int x = 0; x < 5; x++){
        int u = i + d[x].fi;
        int v = j + d[x].se;
        if (min(u,v) <= 0){
            continue;
        }
        if (max(u,v) >= 5){
            continue;
        }
        a[u][v] = !a[u][v];
    }
}

void print(){
    cout << "==!==" << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
}

void solve(int i, int j, int cnt){
    if (cnt == 0 or cnt == 16){
        ans = min(ans, temp);
    }
    if (temp >= ans){
        return;
    }
    if (j > n){
        j = 1;
        i++;
    }
    if (i > n){
        return;
    }
    solve(i, j + 1, cnt);

    cnt -= at(i,j);
    flip(i,j);
    cnt += at(i,j);
    temp++;
    if (i >= 2 and j >= 2 and a[i - 1][j] != a[i - 1][j - 1]){
        temp--;
        flip(i,j);
        return;
    }
    solve(i, j + 1, cnt);
    temp--;
    flip(i,j);
}

signed main(){
    // freopen("flipcoins.INP", "r", stdin);
    // freopen("flipcoins.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                char x;
                cin >> x;
                a[i][j] = (x == 'H');
                cnt += a[i][j];
            }
        }
        ans =  1e18;
        solve(1,1,cnt);
        if (ans == 1e18){
            cout << "Impossible" << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}