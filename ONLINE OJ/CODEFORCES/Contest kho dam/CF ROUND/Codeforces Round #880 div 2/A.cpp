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
        map <int,int> cnt;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            cnt[x]++;
        }
        int last = 1e18;
        int lastv = -1;
        int ok = 1;
        for (auto i: cnt){
            if (last >= i.se and lastv + 1== i.fi){
                last = i.se;
                lastv = i.fi;
                continue;
            }
            ok = 0;
            break;
        }
        if (ok){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}