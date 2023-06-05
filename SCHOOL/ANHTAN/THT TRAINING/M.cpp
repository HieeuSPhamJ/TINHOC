#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

int cnt[5];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    int res = cnt[4];
    res += cnt[3];
    if (cnt[3] >= cnt[1]){
        cnt[1] = 0;
    }
    else{
        cnt[1] -= cnt[3];
    }
    res += cnt[2] / 2;
    cnt[2] %= 2;
    if (cnt[2]){
        res++;
        cnt[1] -= 2;
        if (cnt[1] < 0){
            cnt[1] = 0;
        }
    }
    res += cnt[1] / 4 + (cnt[1] % 4 > 0);

    cout << res << endl;
    return 0;
}