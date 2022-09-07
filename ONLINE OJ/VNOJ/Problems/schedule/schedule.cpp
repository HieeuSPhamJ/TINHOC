#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;
ii a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n);

    int ans = 0;

    for (int i = 1; i <= n; i++){
        // cout << a[i].fi << " " << a[i].se << endl;
        int left = i + 1;
        int right = n;
        int j = 0;
        while(left <= right){
            int mid = (left + right) / 2;
            if (a[i].se > a[mid].fi){
                j = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        // cout << i << "-" << j << endl;
        if (j == 0){
            continue;
        }
        ans += (j - i);
    }

    cout << ans;
    return 0;
}