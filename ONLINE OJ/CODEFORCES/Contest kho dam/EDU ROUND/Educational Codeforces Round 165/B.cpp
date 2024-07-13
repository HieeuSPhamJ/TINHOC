#include"bits/stdc++.h"
#define int long long
//#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        int res = 0;
        deque <int> ls;
        for (int i = 0; i < s.length(); i++){
            ls.push_back(s[i] - '0');
        }
        
        int cnt1 = 0;
        while(ls.size()){
            while(ls.size() and ls.front() == 0){
                ls.pop_front();
            }
            while(ls.size() and ls.back() == 1){
                ls.pop_back();
            }
            // for (auto i: ls){
            //     cout << i;
            // }
            // cout << endl;
            int cnt0 = 0;
            while(ls.size() and ls.front() == 1){
                ls.pop_front();
                cnt1++;
            }
            while(ls.size() and ls.front() == 0){
                ls.pop_front();
                cnt0++;
            }
            // cout << cnt1 << " " << cnt0 << endl;
            res += cnt0 * (cnt1 + 1);
        }
        cout << res << endl;
    }
    return 0;
}

/*
01234
11

*/