#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
// #define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

vector <int> lp;
bool notprime[maxN];
 
bool isPrime(int n, int k){
    if (n < 2){
        return 0;
    }
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}


void ERAS(){
    for (int i = 2; i * i < maxN; i++){
        if (notprime[i] == 0){
            for (int j = i * i; j < maxN; j += i){
                notprime[j] = 1;
            }
        }
    }

    for (int i = 2; i < maxN; i++){
        if (notprime[i] == 0){
            lp.push_back(i);
            // cout << i << " ";
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ERAS();

    int n;
    cin >> n;
    for (;n;n--){
        for (auto i: lp){
            if (n % i == 0 and isPrime(n / i, 4)){
                cout << n;
                return 0;
            }
        }
    }
    


    return 0;
}