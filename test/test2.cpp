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

int notprime[maxN];
int nxt[maxN];

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
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    init();
    while(test--){
        int n;
        cin >> n;
        map <int,int> cnt;
        for (int i = 1; i <= n; i++){
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
        for (auto i: cnt){
            if (i.se % n){
                cout << "NO" << endl;
                goto bru;
            }
        }
        cout << "YES" << endl;
        bru:;
    }
    return 0;
}