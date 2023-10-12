#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int ok = 0;
        int x = n / 3 + 10;
        for(int i = max(1ll,x - 20); i <= x; i++){
            for(int j = i + 1; j <= x; j++){
                for(int k = j + 1; k <= x; k++){
                    if(i % 3 and j % 3 and k % 3 and i + j + k == n){
                        cout << "YES" << endl;
                        cout << i << " " << j << " " << k << endl;
                        goto bru;
                    }
                }
            }
        }
        cout << "NO" << endl;
        bru:;
    }
    return 0;
}

/*
1 1 2
1
2 2 1
2

9 - 1 - 4
*/