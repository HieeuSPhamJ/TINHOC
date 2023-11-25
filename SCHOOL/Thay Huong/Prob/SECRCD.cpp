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
const int mod = 1e9 + 7;

int notprime[maxN];
int nxt[maxN];
int cnt[maxN];

void init(){
    notprime[1] = 1;
    for (int i = 2; i * i < maxN; i++){
        if (notprime[i] == 0){
            for (int j = 2 * i; j < maxN; j += i){
                notprime[j] = 1;
                nxt[j] = i;
            }
        }
    }
    for (int i = 1; i < maxN; i++){
        if (nxt[i] == 0){
            nxt[i] = i;
        }
    }
}

signed main(){
    freopen("SECRCD.INP", "r", stdin);
    freopen("SECRCD.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        // cout << x << ": " << endl;
        while(nxt[x] != x){
            cnt[nxt[x]]++;
            // cout << nxt[x] << " ";
            x /= nxt[x];
        }
        if (x != 1){
            cnt[x]++;
            // cout << x;
        }
        // cout << endl;
    }

    int res = 1;
    for (int i = 2; i < maxN; i++){
        // cout << cnt[i] << " ";
        (res *= cnt[i] + 1) %= mod;
    }
    cout << res << endl;
    return 0;
}