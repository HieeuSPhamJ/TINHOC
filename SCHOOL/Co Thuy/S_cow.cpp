#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 6010;
const int mod = 1e9 + 7;

ii a[maxN];
int dp[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> a[i].fi;
        a[i].se = 0;
    }
    for (int i = n + 1; i <= 2 * n; i++){
        cin >> a[i].fi;
        a[i].se = 1;
    }
    n = 2 * n;
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++){
        for (int j = i - 1; j >= 0; j--){

        }
    }


    return 0;
}

/*
i: xet chuong thu i
k: còn k con bò chưa đc chọn trc i
pre[i]: so con bo be hon i
dp[i][k] = sum(
    dp[j][]
)

1 1* 2 2* 2* 3 3* 4
  

2 2 2* 2*

*/