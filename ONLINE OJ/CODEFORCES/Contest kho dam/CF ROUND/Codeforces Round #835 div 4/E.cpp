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

int a[maxN];

int suf0[maxN];
int prefix1[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        // cout << "TEST" << endl;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            prefix1[i] = prefix1[i - 1] + a[i];
        }
        suf0[n + 1] = 0;
        for (int i = n; i >= 1; i--){
            suf0[i] = suf0[i + 1] + (a[i] == 0);
        }

        int ans = 0;
        for (int i  = 1; i <= n; i++){
            if (a[i]){
                ans += suf0[i];
            }
        }
        // cout << ans << endl;
        int tans = ans;
        for (int i = 1; i <= n; i++){
            // cout << i << ": ";
            if (a[i]){
                // cout << suf0[i + 1] << " " << prefix1[i - 1] << " " << ans - suf0[i + 1] + prefix1[i - 1] << endl;
                tans = max(tans, ans - suf0[i + 1] + prefix1[i - 1]);
            }
            else{
                
                // cout << prefix1[i - 1] << " " << suf0[i + 1] << " " << ans + suf0[i + 1] - prefix1[i - 1] << endl;
                tans = max(tans, ans + suf0[i + 1] - prefix1[i - 1]);
            }
        }
        cout << max(tans, ans) << endl;
    }
    return 0;
}