#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int countDiv[maxN];



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        countDiv[i % k]++;
    }

    int ans = countDiv[0] * countDiv[0] * countDiv[0];

    if (k % 2 == 0){
        ans += 3 * countDiv[k / 2] * countDiv[k / 2] * countDiv[0];
    }

    cout << ans;

    return 0;
}