#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int cnt[maxN];
int greaterthan[maxN];
int b[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int ma = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt[x]++;
        ma = max(ma,x);
        greaterthan[x]++;
        b[x + 1]--;
        b[x / 2 + x % 2]++;
    }

    for (int i = 1; i <= ma; i++){
        b[i] += b[i - 1];
        // cout << b[i] << " ";
    }
    // cout << endl;

    for (int i = ma; i >= 1; i--){
        greaterthan[i] += greaterthan[i + 1];
    }
    int res = 0;
    for (int i = ma; i >= 1; i--){
        if (greaterthan[i] % 2){
            res += b[i];
        }
    }
    cout << res << endl;
    return 0;
}