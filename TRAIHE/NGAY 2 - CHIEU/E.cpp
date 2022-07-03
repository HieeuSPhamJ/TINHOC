#include<bits/stdc++.h>
#define ii pair <int,int>
#define int long long
#define f first
#define s second
using namespace std;

const int maxN = 1e6 + 10;
const int maxNN = 1e7 + 10;

int numDiv[maxN];
bool notPrime[maxNN];

void init(){
    for (int i = 1; i <= maxN; i++){
        for (int j = 1; i * j <= maxN; j++){
            numDiv[i * j]++;
        }
        // cout << numDiv[i] << ' ';
    }

}

int checkPrime(int n){
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

int fastPow(int n, int a){
    if (a == 1){
        return n;
    }
    int temp = fastPow(n, a / 2);
    if (a % 2 == 1){
        return temp * temp * n;
    }
    return (temp * temp);
}

int checkCP(int n){
    int sq = sqrt(n);
    for (int i = -3; i <= 3; i++){
        if ((sq + i) * (sq + i) == n){
            return sq + i;
        }
    }

    return 0;
}


signed main(){
    freopen("divpow.inp", "r", stdin);
    freopen("divpow.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    int n;
    cin >> n;
    int sq = checkCP(n);
    if (sq and checkPrime(sq)){
        cout << sq;
        return 0;
    }

    // cout << pow((double)1552, double(1/3));

    for (int i = 1; i * i * i <= n and i <= 1e8; i++){
        if (n % i != 0){
            continue;
        }
        if (fastPow(i, numDiv[i]) == n){
            cout << i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}