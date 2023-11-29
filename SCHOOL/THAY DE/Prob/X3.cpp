#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + !0;

int Count[40];
int a[maxN];

signed main(){
    freopen("X3.INP", "r", stdin);
    freopen("X3.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[i] = x;
        for (int j = 0; j <= 30; j++){
            Count[j] += ((x & (1ll << j)) > 0);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int x = a[i];
        for (int j = 0; j <= 30; j++){
            int bit = ((x & (1ll << j)) > 0);
            if (bit == 0){
                ans += Count[j] * (1ll << j);
            }
            else{
                ans += (n - Count[j]) * (1ll << j);
            }
        }
    }
    ans /= 2;
    cout << ans << endl;

    
    return 0;
}