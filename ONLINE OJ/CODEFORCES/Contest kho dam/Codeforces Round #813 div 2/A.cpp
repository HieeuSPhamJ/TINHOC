#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 110;

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
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        int ans = 0;

        for (int i = 1; i <= k; i++){
            if (a[i] > k){
                ans++;
            }
        }

        cout << ans;

        cout << endl;
    }
    return 0;
}