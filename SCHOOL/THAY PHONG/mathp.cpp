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

bool notPrime[maxN + 10];
int low[maxN + 10];
bool check[maxN];

void init(){
    check[1] = 1;
    notPrime[0] = notPrime[1] = 1;

    for (int i = 2; i * i <= maxN; i++){
        if (notPrime[i] == 0){
            for (int j = i * i; j <= maxN; j += i){
                notPrime[j] = 1;
                low[j] = i;
            }
        }
    }

    for (int i = 1; i <= maxN; i++){
        if (notPrime[i] == 0){
            low[i] = i;
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    int hasOne = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        int t = x;
        if (x == 1){
            continue;
        }
        while(x <= maxN){
            check[x] = 1;
            x *= t;
        }
    }
    init();

    while(test--){
        int x;
        cin >> x;
        vector <int> primes;
        int tx = x;
        while(tx > 1){
            // cout << tx << " " << low[tx] << endl;
            primes.push_back(low[tx]);
            tx /= low[tx];
        }
        int ok = hasOne;
        for (int i = 0; i < primes.size(); i++){
            for (int j = i + 1; j < primes.size(); j++){
                int p1 = primes[i];
                int p2 = primes[j];
                
                tx = x / (p1 * p2);
                if (check[tx]){
                    ok = 1;
                    goto lmao;
                }
            }
        }
        lmao:;
        if (ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}