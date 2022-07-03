#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int mod = 998244353;
const int maxN = 2 * 1e5;
int a[maxN];
int b[maxN];
vector <int> listPrime;
int notPrime[maxN];
int maxI;

void init(){
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i * i < maxN; i++){
        if (notPrime[i] == 0){
            for (int j = 2; i * j < maxN; j++){
                notPrime[i * j] = 1;
            }
        }
        
    }
    for (int i = 2; i < maxN; i++){
        if (notPrime[i] == 0){
            listPrime.push_back(i);
            // cout << i << ' ';
        }
    }
}

void phantichP(int n){
    for (int i = 0; i < listPrime.size(); i++){
        if (n <= 1){
            break;
        }
        while(n % listPrime[i] == 0){
            n /= listPrime[i];
            a[i]++;
            maxI = max(maxI, i);
            // cout << listPrime[i] << ' ';
        }
    }
    // cout << endl;
}

void phantichQ(int n){
    for (int i = 0; i < listPrime.size(); i++){
        if (n <= 1){
            break;
        }
        while(n % listPrime[i] == 0){
            n /= listPrime[i];
            b[i]++;
            maxI = max(maxI, i);
            // cout << listPrime[i] << ' ';
        }
    }
    // cout << endl;
}

signed main(){
    // freopen("gcdlcm.inp", "r", stdin);
    // freopen("gcdlcm.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    // phantichP(100);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        phantichP(inp);
    }
    for (int i = 1; i <= m; i++){
        int inp;
        cin >> inp;
        phantichQ(inp);
    }

    int ans = 1;

    for (int i = 0; i <= maxI; i++){
        if (a[i] != b[i] and a[i] != 0){
            ans *= 2;
            ans %= mod;
        }
    }

    cout << ans;
    return 0;
}