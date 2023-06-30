#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3e5 + 10;

int down[maxN];
int up[maxN];
int a[maxN];

set <int> sto[100];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            char x;
            cin >> x;
            down[i] = x - '0';
        }
        for (int i = 1; i <= n; i++){
            char x;
            cin >> x;
            up[i] = x - '0';
        }
        int m = s.length();

        for (int i = 0; i <= 9; i++){
            sto[i].clear();
        }
        for (int i = 1; i <= m; i++){
            a[i] = s[i - 1] - '0';
            sto[a[i]].insert(i);
        }

        for (int i = 1, last = 0; i <= n; i++){
            int x = last;
            for (int c = down[i]; c <= up[i]; c++){
                if (sto[c].upper_bound(last) != sto[c].end()){
                    x = max(x, *sto[c].upper_bound(last));
                }
                else{
                    cout << "YES" << endl;
                    goto bru;
                }
            }
            last = max(last,x);
        }
        cout << "NO" << endl;
        bru:;
    }
    return 0;
}


