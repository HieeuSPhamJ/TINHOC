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
        multiset <int> s;
        while (n--){
            int x;
            cin >> x;
            s.insert(x);
        }
        int ans = 0;
        while(s.size()){
            ans++;
            if (s.begin() == s.end()){
                break;
            }
            int x = *s.begin();
            s.erase(s.begin());
            while(s.find(x + 1) != s.end()){
                s.erase(s.find(x + 1));
                x++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}