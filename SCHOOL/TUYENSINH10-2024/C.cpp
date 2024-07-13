#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];
int prefix_sum[maxN];
int prefix_even[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("bai3.inp", "r")) {
        freopen("bai3.inp", "r", stdin);
        freopen("bai3.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
        prefix_even[i] = prefix_even[i - 1] + (a[i] % 2 == 0);
    }

    int res = 0;
    int last_sum = -1e18;
    int last_even = -1e18;

    for (int i = 1; i + k - 1 <= n; i++){
        int cur_sum = prefix_sum[i + k - 1] - prefix_sum[i - 1];
        int cur_even = prefix_even[i + k - 1] - prefix_even[i - 1];
        if (cur_sum > last_sum){
            res = i;
            last_sum = cur_sum;
            last_even = cur_even;
        }
        else if (cur_sum == last_sum and cur_even > last_even){
            res = i;
            last_sum = cur_sum;
            last_even = cur_even;
        }
    }

    cout << res << " " << res + k - 1;

    return 0;
}