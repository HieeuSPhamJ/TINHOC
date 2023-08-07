#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2000;

    int n, k;
int a[maxN];

int check(int x){
    for (int i = 1; i < n; i++){
        // cout << "With: " << i << endl;
        if (a[i] >= x){
            // cout << "lon" << endl;
            return 1;
        }
        int t = 0;
        int xx = x;
        for (int j = i; j <= n; j++){
            // cout << j << ": "<< xx - a[j] << endl;
            if (max(0ll, xx - a[j]) == 0){
                break;
            }
            if (j == n){
                t = 1e18;
                break;
            }
            t += max(0ll, xx - a[j]);
            if (t > k){
                break;
            }
            xx--;
        }
        if (t <= k){
            // cout << "ok at " << i << " " << t << endl;
            return 1;
        }
    }
    return a[n] >= x;
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
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        int l = *max_element(a + 1, a + 1 + n);
        int r = 1e18;
        int res = l;

        while(l <= r){
            int mid = (l + r) / 2;
            if (check(mid)){
                l = mid + 1;
                res = mid;
            }
            else{
                r = mid - 1;
            }
        }

        // cout << check(7) << endl;
        
        cout << res << endl;
    }
    return 0;
}