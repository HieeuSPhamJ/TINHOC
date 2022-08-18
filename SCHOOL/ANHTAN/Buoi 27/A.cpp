#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];

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

    int left = 1;
    int ans = 0;
    while(left < n){
        int L = left;
        // cout << "#" << L << endl;
        int tempAns = 0;
        for (int i = L + 1; i <= n; i++){
            // cout << i << ' ';
            int t = a[L] - a[i];
            if (t <= 0){
                left = i;
                break;
            }
            tempAns += t;
            if (i == n){
                // cout << '*';
                left++;
                tempAns = 0;
            }
        }
        // cout << endl;
        // cout << tempAns << endl;
        ans += tempAns;
    }

    cout << ans;
    return 0;
}