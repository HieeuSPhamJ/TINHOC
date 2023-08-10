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
        set <int> cnt;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            cnt.insert(x);
        }

        vector <int> ls;

        for (auto i: cnt){
            ls.push_back(i);
        }

        int l = 0;
        int r = ls.back();
        int ans = -1;

        while(l <= r){
            int mid = (l + r) / 2;
            cout << "With: " << mid << endl;
            vector <ii> s;
            for (auto i: ls){
                int L = i - mid;
                int R = i + mid;
                s.push_back({max(L,0ll), min((int)(1e9),R)});
                cout << max(L,0ll) << "-" << min((int)(1e9),R) << endl;
            }

            sort(all(s));
            int res = 0;
            set <int> se;
            for (auto i: s){
                // cout << *se.begin() << " " << i.fi << endl;
                if (se.size() and *se.begin() < i.fi){
                    // cout << i.fi << " " << i.se << endl;
                    res++;
                    se.clear();
                }
                se.insert(i.se);
            }
            if (s.size()){
                res++;
            }
            // cout << res << endl;
            if (res <= 3){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
2 
*/