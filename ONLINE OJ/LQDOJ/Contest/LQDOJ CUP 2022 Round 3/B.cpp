#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, test;
int mi = 1e18, ma = 0;

int a[maxN];
int pref[maxN];

int sum(int l, int r){
    return pref[r] - pref[l - 1];
}

signed main(){
    freopen("SHOPPING.inp", "r", stdin);
    freopen("SHOPPING.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        mi = min(mi, a[i]);
        ma = max(ma, a[i]);
        pref[i] = pref[i - 1] + a[i];
    }
    // cout << mi << " " << ma << endl;
    while(test--){
        int start, l, r, k;
        cin >> start >> l >> r >> k;
        int ans = 0;
        if (l <= mi and ma <= r){
            int left = start;
            int right = n;
            while(left <= right){
                int mid = (left + right) / 2;
                int s = sum(start, mid);
                // cout << left << " " << mid << " " << right << " " << s << endl;
                if (s > k){
                    right = mid - 1;
                }
                else{
                    ans = max(ans, (mid - start + 1));
                    left = mid + 1;
                }
            }
            cout << ans << endl;
        }
        else{
            ans = 0;
            for (int i = start; i <= n; i++){
                if (l <= a[i] and a[i] <= r){
                    if (k >= a[i]){
                        k -= a[i];
                    }
                    else{
                        break;
                    }
                }
                ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}