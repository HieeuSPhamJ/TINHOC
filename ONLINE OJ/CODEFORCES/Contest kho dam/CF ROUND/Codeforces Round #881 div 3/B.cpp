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

int a[maxN];

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
        for (int i = 1; i <= n; i++){   
            cin >> a[i];
        }

        int check = 0;
        int res = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] < 0){
                sum -= a[i];
            }
            else{
                sum += a[i];
            }
            if(i == 1 && a[i] < 0)
            {
                check = true;
                res++;
            }
            else if(a[i] < 0 && !check)
            {
                res++;
                check = true;
            }
            else if(a[i] > 0)
                check = false;
        }
        cout << sum << " " << res << endl;
    }
    return 0;
}