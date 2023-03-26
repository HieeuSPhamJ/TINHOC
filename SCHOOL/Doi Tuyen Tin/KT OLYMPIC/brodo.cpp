#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
// #define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5010;

int a[maxN];
int check[maxN];
map <int,int> dir;

signed main(){
    freopen("brodo.INP", "r", stdin);
    freopen("brodo.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dir[a[i]] = i;
        // cout << a[i] << " " << dir[a[i]] << endl;
    }

    int ans = 0;
    int limit = 0;
    for (int i = 1; i <= n; i++){
        if (check[i] == 0){
            // cout << "With: " << i << endl;
            ans++;
            check[i] = 2;
            int K = 0;
            int T = 0;
            for (int j = i + 1; j <= n; j++){
                if (check[j] == 2 or check[j] == 0){
                    int k = a[j] - a[i];
                    int turn = 1;
                    for (int e = a[j]; dir[e] != 0; e += k){
                        turn++;
                        limit++;
                    }
                    if (turn > T){
                        T = turn;
                        K = k;
                    }
                }
            }
            if (T == 0){
                continue;
            }
            // cout << T << " " << K << endl;
            for (int j = a[i] + K; dir[j] != 0; j += K){
                check[dir[j]] = 1;
                // cout << dir[j] << " ";
            }
            // cout << endl;
            check[dir[a[i] + K * (T - 1)]] = 2;
        }
    }
    
    cout << ans;

    return 0;
}