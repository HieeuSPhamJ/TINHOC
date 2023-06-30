#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2e5 + 7;
const int inf = 1e18;

int l[maxN];
int r[maxN];
int query[maxN];
int sum[maxN];
int n , m , q;

bool check(int x){
    for (int i = n ; i >= 1; i--){
        sum[i] = 0;
    }
    for (int i = 1 ; i <= x; i++) {
        if (i <= x){
            int temp = query[i];
            sum[temp] = 1;
        }
    }
    for (int i = 1 ; i <= n ; i++){
        sum[i] += sum[i - 1];
    }

    for(int i = 1 ; i <= m ; i++){
        if (sum[r[i]] - sum[l[i]-1] > (r[i] - l[i] + 1) / 2){
            return true;
        }
    }
    return false;

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
        cin >> n >> m;
        for (int i = 1 ; i <= m ; i++) {
            cin >> l[i] >> r[i];
        }
        cin >> q;
        for(int i = 1 ; i <= q ; i++){
            int x; cin >> x; 
            query[i] = x;
        }
        int ans = -inf;
        int l = 1;
        int r = q;
        while(l <= r){
            int mid = (l + r) >> 1;
            if (check(mid)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if (ans == -inf){
            cout << -1 << endl;
        }
        else{
            cout << ans << endl;
        }
    }
    return 0;
}