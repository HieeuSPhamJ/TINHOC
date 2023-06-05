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

int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= m; i++){
        cin >> a[i];
        sum += a[i];
    }

    int l = 1;
    int r = sum;
    int res = sum;

    while(l <= r){
        int mid = (l + r) / 2;
        int tres = 0;

        for (int i = 1; i <= m; i++){
            tres += a[i] / mid;
            tres += (a[i] % mid != 0);
        }
        if (tres <= n){
            r = mid - 1;
            res = min(res, mid);
        }
        else{
            l = mid + 1;
        }
    }

    cout << res << endl;

    return 0;
}