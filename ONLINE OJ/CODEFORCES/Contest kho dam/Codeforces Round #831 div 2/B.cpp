#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
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
        vector <ii> lists;
        vector <ii> lists2;
        for (int i = 1; i <= n; i++){
            int a, b;
            cin >> a >> b;
            lists.push_back({max(a,b), min(a,b)});
            lists2.push_back({min(a,b), max(a,b)});
        }     
        lists.push_back({0,0});
        sort(lists.begin(), lists.end());
        lists.push_back({0,0});

        lists2.push_back({0,0});
        sort(lists2.begin(), lists2.end());
        lists2.push_back({0,0});

        int x = 0;
        int y = 0;

        for (int i = 1; i < (int)lists.size(); i++){
            x += lists[i].se;
            y += abs(lists[i - 1].fi - lists[i].fi);
        }
        int ans = x * 2 + y;

        x = 0;
        y = 0;
        
        for (int i = 1; i < (int)lists2.size(); i++){
            x += lists2[i].se;
            y += abs(lists2[i - 1].fi - lists2[i].fi);
        }
        
        ans = min(ans, x * 2 + y);
        cout << ans << endl;
    }
    return 0;
}