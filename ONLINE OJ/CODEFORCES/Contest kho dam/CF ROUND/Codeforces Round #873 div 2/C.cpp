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
const int mod = 1e9 + 7;

int a[maxN];
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
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }

        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        
        int ans = 1;

        for (int i = 1; i <= n; i++){
            int far = upper_bound(a + 1, a + n + 1, b[i]) - a;
            if (n - far + 1 - (n - i) < 0){
                ans = 0;
                break;
            }
            ans *= (n - far + 1 - (n - i));

            ans %= mod;
        }

        cout << ans << endl;
    }
    return 0;
}