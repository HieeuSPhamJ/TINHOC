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
        vector <int> lists;
        for (int i = 1; i <= n; i++){
            int a;
            cin >> a;
            lists.push_back(a);
        } 
        sort(lists.begin(), lists.end());
        int ans = 0;

        ans = abs(lists.back() - lists.front()) + abs(lists.back() - lists[n - 2]);

        if (n == 3){
            ans = max(ans,abs(lists.front() - lists.back()) + abs(lists.front() - lists[n - 2]));
            ans = max(ans,abs(lists.front() - lists[n - 2]) + abs(lists.back() - lists[n - 2]));
        }

        cout << ans << endl;
    }
    return 0;
}