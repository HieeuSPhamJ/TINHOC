#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 500010;

int n;
ii a[maxN];
int b[maxN];


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i].fi >> a[i].se;
        }

        for (int i = 0; i <= n + 3; i++){
            b[i] = -1;
        }

        sort(a + 1, a + 1 + n);

        int ans = 1e18;

        b[n] = a[n].se;
        for (int i = n - 1; i >= 0; i--)
            b[i] = max(b[i + 1], a[i].se);

        set<int> s;
        for (int i = 1; i <= n; i++){
            int ma = b[i + 1];
            if (i != n){
                ans = min(ans, abs(ma - a[i].fi));
            }

            if (s.size() and ma < a[i].fi){
                auto now = s.lower_bound(a[i].fi);
                auto nnow = now;
                now++;
                if (now != s.end()){
                    ans = min(ans, abs(*now - a[i].fi));
                    if (now != s.begin()){
                        ans = min(ans, abs(*nnow - a[i].fi));
                    }
                }
                else{
                    ans = min(ans, abs(*nnow - a[i].fi));
                }
            }
            s.insert(a[i].se);
        }

        cout << ans << endl;
    }
    return 0;
}