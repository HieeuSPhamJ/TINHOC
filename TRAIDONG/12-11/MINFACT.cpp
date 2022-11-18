#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int NPRIME;
vector <int> primes;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        int nn = n;
        for (int i = 2; i * i <= nn; i++){
            if (nn % i == 0){
                primes.push_back(i);
                NPRIME++;
                while(nn % i == 0){
                    nn /= i;
                }
            }
        }
        if (nn != 1) {
            primes.push_back(nn);
        }
        
    }
    return 0;
}