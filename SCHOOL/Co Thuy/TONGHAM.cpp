#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;
const int mod = 998244353;

int a[maxN];
int b[maxN];
int cnt[maxN];

signed main(){
    freopen("TONGHAM.INP", "r", stdin);
    freopen("TONGHAM.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        // cout << b[i] << " ";
    }
    // cout << endl;
    cnt[1] = n;
    cnt[n] = n;
    for (int i = 2, temp = n - 2; temp >= 0; i++){
        cnt[i] = (cnt[i - 1] + temp);
        temp -= 2;
    }
    for (int i = n - 1, temp = n - 2; temp >= 0; i--){
        cnt[i] = (cnt[i + 1] + temp);
        temp -= 2;
    }

    // for (int i = 1; i <= n; i++){
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;

    priority_queue <int> myHeap;

    for (int i = 1; i <= n; i++){
        myHeap.push((a[i] * cnt[i]));
    }

    sort(b + 1, b + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int temp = myHeap.top();
        // cout << temp << " " << b[i] << endl;
        myHeap.pop();
        (ans += (temp % mod * b[i]) % mod) %= mod;
    }
    cout << ans;

    

    return 0;
}