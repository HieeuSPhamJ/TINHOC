#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

vector <int> primes;
// int cnt;

bool check(int x){  
    for (auto i: primes){
        // cnt++;
        if (x % i == 0){
            return 0;
        }
        if (i * i >= x){
            break;
        }
    }
    return 1;
}

int cal(int l, int r){
    int res = 0;
    for (int i = l; i <= r; i++){
        res += check(i);
    }
    return res;
}

const int maxN = sqrt(1e9 + 20);

int notPrime[maxN + 10];

void init(){
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i * i <= maxN - 1; i++){
        if (notPrime[i] == 0){
            for (int j = i * i; j <= maxN - 1; j += i){
                notPrime[j] = 1;
            }
        }
    }
    for (int i = 2; i < maxN; i++){
        if (notPrime[i] == 0){
            // cout << i << " ";
            primes.push_back(i);
        }
    }
    // cout << endl;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    int test;
    cin >> test;
    while(test--){
        int l, r;
        cin >> l >> r;
        cout << cal(l, r) << endl;
    }
    // cerr << cnt;
    return 0;
}