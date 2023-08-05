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
int pre[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);

    int res = 1e18;
    for (int i = 2; i <= n; i++){
        int l = 1;
        int r = i;
        int j = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            
            if (a[i] - a[mid] + 1 == i - mid + 1 and mid == 1){
                l = mid + 1;
            }
            else if ((a[i] - a[mid] + 1) > n){
                l = mid + 1;
            }
            else{
                r = mid - 1;
                j = mid;
            }
        }
        if (j == -1){
            continue;
        }
        // cout << i << " " << n - (i - j + 1) << endl;
        res = min(res, n - (i - j + 1));
    }

    cout << res << endl;
    cout << max(a[n] - a[2] + 1, a[n - 1] - a[1] + 1) - (n - 1) << endl;
    return 0;
}