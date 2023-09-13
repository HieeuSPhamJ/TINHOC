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
            char c;
            cin >> c;
            a[i] = (c == '1');
        }
        int cnt = 0;
        int res = 0;
        int ma = n;
        for (int i = 0; 1 + i < n - i; i++){    
            if (a[1 + i] != a[n - i]){
                res++;
                ma--;
            }
        }
        if (n % 2 == 0){
            for (int i = 0; i <= n; i++){
                if (i >= res and i <= ma){
                    if ((i - res) % 2){
                        cout << 0;
                    }
                    else{
                        cout << 1;
                    }
                }
                else{
                    cout << 0;
                }
            }
            cout << endl;
        }
        else{
            for (int i = 0; i <= n; i++){
                if (i >= res and i <= ma){
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
            cout << endl;
        }
    }
    return 0;
}