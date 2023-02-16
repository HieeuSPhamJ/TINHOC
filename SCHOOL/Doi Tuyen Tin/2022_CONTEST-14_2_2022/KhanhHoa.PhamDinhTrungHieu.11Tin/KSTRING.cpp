#include <bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define iii pair <int,ii>
#define endl '\n'
#define fi first
#define se second
#define all(x) x.begin(),x.end()
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int check[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("KSTRING.INP","r", stdin);
    freopen("KSTRING.OUT","w", stdout);
    int n, d;
    cin >> n >> d;

    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        a[i] = x - 'a';
    }

    for (int k = 1; k <= n; k++){
        int ans = 0;
        int m = n / k;
        if (check[k]){
            cout << 0 << " ";
            continue;
        }

        for (int t1 = 0; t1 < m; t1++){
            for (int t2 = t1 + 1; t2 < m; t2++){
                int ok = d;
                for (int i = 1; i <= k; i++){
                    if (a[t1 * k + i] != a[t2 * k + i]){
                        ok--;
                    }
                    if (ok < 0){
                        break;
                    }
                }
                ans += (ok >= 0);
            }
        }
        if (ans == 0){
            for (int j = 2; k * j <= n; j++){
                check[j * k] = 1;
            }
        }
        cout << ans << " ";
    }

    return 0;
}

