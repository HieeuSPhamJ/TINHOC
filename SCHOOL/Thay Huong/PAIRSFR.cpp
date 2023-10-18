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

int uoc[maxN];

void init(){
    for (int i = 1; i < maxN; i++){
        for (int j = 2 * i; j < maxN; j += i){
            uoc[j] += i;
        }
    }
}

signed main(){
    // freopen("PAIRSFR.INP", "r", stdin);
    // freopen("PAIRSFR.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int l, r;
    cin >> l >> r;
    int cnt = 0;
    int cnthh = 0;
    for (int i = l; i <= r; i++){
        // cout << uoc[i] << endl;
        if (i != uoc[i] and l <= uoc[i] and uoc[i] <= r and uoc[uoc[i]] == i){
            // cout << i << " " << uoc[i] << endl;
            cnt++;
        }
        cnthh += (uoc[i] == i);
    }
    cout << cnt / 2 + cnthh;
    return 0;
}

/*
6 28 284 496
*/