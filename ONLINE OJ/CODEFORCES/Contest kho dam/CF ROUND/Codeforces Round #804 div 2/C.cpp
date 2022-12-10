#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;

int a[maxN];
int fact[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;

    fact[0] = 1;

    for (int i = 1; i < maxN; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }

    while(test--){
        int n;
        cin >> n;
        
        int open = -1;
        int close = -1;
        int check = 0;
        
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (close != -1){
                if (a[i] == 2 and i != n){
                    check = 1;
                }
            }
            if (a[i] == 1 or a[i] == 0){
                if (open == -1){
                    open = i;
                }
                else{
                    close = i;
                }
            }
        }

        if (n == 1){
            cout << 1 << endl;
            continue;
        }

        // cout << open << ' ' << close << ' ' << check << endl;

        cout << (((fact[open - 1] * fact[close - open - 1]) % mod) * fact[n - check - close]) % mod;

        cout << endl;
    }
    cout << 78;

    return 0;
}