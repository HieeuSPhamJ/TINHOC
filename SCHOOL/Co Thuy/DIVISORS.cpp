#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
int a[maxN];

signed main(){
    freopen("Divisors.INP", "r", stdin);
    freopen("Divisors.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);

        int check = a[1] * a[n];
        for (int i = 1; i <= n; i++){
            // cout << a[i] << " ";
            if (a[i] * a[n - i + 1] != check){
                check = -1;
            }
        }
        int cnt = 0;
        if (check == -1){
            cout << -1 << endl;
            continue;
        }
        for (int i = 2; i * i <= check; i++){
            if (check % i == 0){
                cnt++;
                // cout << i << " ";
                if (check / i != i){
                    cnt++;
                    // cout << check / i << endl;
                }
            }
        }
        if (cnt != n){
            check = -1;
        }
        // cout << cnt << " ";
        cout << check << endl;
    }
    return 0;
}