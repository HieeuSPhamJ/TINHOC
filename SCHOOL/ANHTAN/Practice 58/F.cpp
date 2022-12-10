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
    int n, l, r;
    cin >> n >> l >> r;
    vector <pair<ii,int>> lists;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        lists.push_back({{a,b}, i});
    }
    sort(lists.rbegin(), lists.rend());
    int last = l;
    vector <int> ans;
    while (!lists.empty() and last < r){
        int nlast = 0;
        int id = -1;
        while(!lists.empty() and lists.back().fi.fi <= last){
            if (nlast <= lists.back().fi.se){
                nlast = lists.back().fi.se;
                id = lists.back().se;
            }
            lists.pop_back();
        }
        if (nlast < last){
            break;
        }
        last = nlast;
        ans.push_back(id);
    }
    if (last < r){
        cout << -1;
        return 0;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto i: ans){
        cout << i << " ";
    }
    return 0;
}