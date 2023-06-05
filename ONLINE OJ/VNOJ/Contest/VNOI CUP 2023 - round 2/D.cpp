#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int cnt[1000];
int pre[1000];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a;
    if (n < m){
            a.resize(m + 3);
        for (int i = 1; i <= m; i++){
            a[i].resize(n + 3);
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[m - j + 1][i];
            }
        }
        swap(n,m);
    }
    else{
        a.resize(n + 3);
        for (int i = 1; i <= n; i++){
            a[i].resize(m + 3);
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    int res = 0;

    for (int r = 2; r <= m; r++){
        for (int l = 1; l < r; l++){
            for (int i = 0; i <= n; i++){
                cnt[i] = 0;
            }
            cout << "With: " << l << " " << r << endl;
            for (int i = 2; i <= n; i++){
                if (a[i][r] >= r - l){
                    cnt[i]--;
                    cnt[i - a[i][l]]++;
                }
            }

            cout << "------" << endl;
            cout << tres << endl;
        }
    }

    cout << res << endl;

    return 0;
}