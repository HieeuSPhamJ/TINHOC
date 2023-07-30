
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int n, mod, k;

int a[maxN];

bool check(int l){
    int i = 0;
    int cnt = 0;
    // cout << "With: " << l << endl;
    while(i != n){
        if (cnt > k){
            return 0;
        }
        int j = i;
        while (a[j + 1] - a[i] <= l and j + 1 <= n){
            j++;
        }
        if (i == j){
            return 0;
        }
        cnt++;
        i = j;
        // cout << i << " ";
    }
    // cout << endl;
    return cnt <= k;
}

signed main(){
    freopen("river.INP", "r", stdin);
    freopen("river.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> mod >> k;
    for (int i = 1; i <= n; i++){
        a[i] = a[i - 1] + 1 + ((i - 1) * (i - 1)) % mod;
        // cout << a[i] << " ";
    }
    // cout << endl;

    int l = 1;
    int r = 1e18;
    int res = -1;
    // cout << check(10) << endl;
    while(l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            res = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << res << endl;

    return 0;
}