#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

ii conv[maxN];
int f[maxN];

void init(){
    conv[1] = {1,0};
    conv[2] = {0,1};
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= maxN; i++){
        conv[i] = {conv[i - 2].fi + conv[i - 1].fi,conv[i - 2].se + conv[i - 1].se};
        f[i] = f[i - 1] + f[i - 2];
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
        int n, k;
        cin >> n >> k;
        if (k > 30){
            cout<< 0 <<endl;
        }
        else{
            int res = 0;
            // cout << a << " " << b << endl;
            for(int j = 1; j * f[k - 1] <= n; j++){
               if ((n - j * f[k - 1]) % f[k - 2] == 0 and (n - j * f[k - 1]) / f[k - 2] <= j){
                  res++;
               }
            }
            cout << res << endl;
        }
    }
    return 0;
}