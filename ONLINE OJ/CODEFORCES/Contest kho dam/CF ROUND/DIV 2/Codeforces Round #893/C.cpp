#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int ok[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        
        a[1] = 1;
        for (int i = 2, last = 2; i <= n; i++){
            if (ok[i] == 1){
                continue; 
            }
            int t = i; 
            while (t <= n){
                a[last] = t; 
                ok[t] = true;
                t = t << 1;
                last++;
            }
        }

        for (int i = 1; i <= n; i++){
            ok[i] = 0;
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}