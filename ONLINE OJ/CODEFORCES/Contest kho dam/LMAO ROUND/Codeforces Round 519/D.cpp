#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int a[11][maxN];
int dir[11][maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int j = 1; j <= m; j++){
        for (int i = 1; i <= n; i++){
            cin >> a[j][i];
            dir[j][a[j][i]] = i;
        }
    }

    int res = 0;

    for (int i = 1; i <= n; i++){
        int far = i;
        for (int j = i + 1; j <= n; j++){
            int ok = 1;
            int t = a[1][j];
            int last = a[1][j - 1];
            for (int k = 2; k <= m; k++){
                if (dir[k][last] + 1 == dir[k][t]){
                    continue;
                }
                ok = 0;
            }
            if (ok){
                far = j;
                continue;
            }
            break;
        }
        res += (far - i + 1) * (far - i) / 2 + (far - i + 1);
        // cout << i << " " << far << endl;
        i = far;
    }

    cout << res << endl;
    return 0;
}

/*
2 3
2 2 
3 3
3 2
*/