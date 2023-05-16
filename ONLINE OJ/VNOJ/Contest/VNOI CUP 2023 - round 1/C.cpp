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

bool cmp(int a, int b){
    return a > b;
}

int a[maxN];
int b[maxN];

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
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }
    
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n, cmp);
        
        int res = 0;       
        for (int i = 1; i <= n; i++){
            res += max(a[i], b[i]);
        }

        cout << res << endl;
    }
    return 0;
}