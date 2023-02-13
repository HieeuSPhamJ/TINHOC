#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

map <int,int> lists;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        lists[x]++;
    }

    int ans = 0;
    int ok = 1;

    for (auto i: lists){
        int cnt = i.se;
        while(cnt - 3 >= 2){
            ans++;
            cnt -= 3;
        }
        if (cnt == 1){
            ok = 0;
            break;
        }
        if (cnt != 0){
            if (cnt - 3 == 0){
                ans++;
            }
            else if (cnt - 4 == 0){
                ans+=2;
            }
            else if (cnt - 2 == 0){
                ans++;
            }
            else{
                ok = 0;
                break;
            }
        }
    }

    if (ok == 0){
        cout << -1 << endl;
        return 0;
    }
    cout << ans;
    return 0;
}