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
    vector <ii> lists;
    set <pair<ii,int>> lmao;
    int cnt = 1;
    while(test--){
        char x;
        cin >> x;
        if (x == 'D'){
            int a, b;
            cin >> a >> b;
            lists.push_back({b,a});
            lmao.insert({{b,a},cnt});
            cnt++;
        }
        else{
            int i;
            cin >> i;
            pair <ii,int> now = {lists[i - 1],0ll};
            cout << "With: " << now.fi.fi << " " << now.fi.se << endl;
            auto it = lmao.lower_bound(now);
            for (auto i: lmao){
                cout << i.fi.fi << " " << i.fi.se << endl;
            }
            if (it == lmao.end()){
                cout << "NE" << endl;
            }
            else{
                auto ans = *it;
                cout << ans.se << endl;
            }
        }
    }
    return 0;
}