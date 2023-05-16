#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2 * 1e5 + 10;

bool cmp(int a, int b){
    return a > b;
}

int a[maxN];


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        int sum = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            sum += a[i];
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++){
            a[i] = a[i - 1] + a[i];
        }
        int res = -1;
        for (int i = 0; i <= k; i++){
            int j = k - i;
            // cout << 2 * j << " " << n - i << endl;
            res = max(res, a[n - i] - a[2 * j]);
        }
        cout << res << endl;

    }
    return 0;
}