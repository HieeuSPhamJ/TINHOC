#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
map <int,int> cnt;

signed main(){
    freopen("SUBSTR.INP", "r", stdin);
    freopen("SUBSTR.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int mid = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x > k){
            a[i] = 1;
        }
        else if (x < k){
            a[i] = -1;
        }
        else{
            mid = i;
        }
    }
    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    for (int i = mid, s = 0; i >= 1; i--){
        s += a[i];
        cnt[s]++;

    }
    int res = 0;
    for (int i = mid, s = 0; i <= n; i++){
        s += a[i];
        res += cnt[-s];
    }

    cout << res << endl;

    return 0;
}