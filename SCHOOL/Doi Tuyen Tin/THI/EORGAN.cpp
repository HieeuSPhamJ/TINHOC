#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'

using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];
int Count[maxN];

signed main(){
    freopen("EORGAN.INP", "r", stdin);
    freopen("EORGAN.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int MA = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        MA = max(MA,a[i]);
        Count[a[i]]++;
    }

    int ans = 0;

    for (int i = 1; i <= MA; i++){
        int tempAns = 0;
        for (int j = 1; i * j <= MA; j++){
            tempAns += Count[i * j];
        }
        if (tempAns >= 2){
            ans = max(ans, tempAns * i);
        }
    }

    cout << ans;


    return 0;
}
