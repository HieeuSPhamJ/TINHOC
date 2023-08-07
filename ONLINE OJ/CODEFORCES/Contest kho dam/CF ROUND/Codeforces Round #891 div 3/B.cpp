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
        vector <int> s;
        string str;
        cin >> str;
        int n = str.length();
        for (int i = 1; i <= n; i++){
            s.push_back(str[i - 1] - '0');
        }
        vector <int> ans;
        int last = -1;
        int tad = 0;
        while(s.size()){
            // cout << "With: " << s.size() << endl;
            int t = s.back() + tad;
            s.pop_back();
            if (t >= 5){
                // cout << "lon" << endl;
                tad = 1;
                ans.push_back(0);
                last = ans.size();
            }
            else{
                tad = 0;
                // cout << "non" << endl;
                ans.push_back(t);
            }
        }
        for (int i = 0; i < (int)ans.size(); i++){
            if (i < last){
                ans[i] = 0;
                // cout << 0;
            }
            else{
                // cout << ans[i];
            }
        }
        // cout << endl;
        if (ans.back() == 0){
            ans.push_back(1);
        }
        reverse(all(ans));
        for (auto i: ans){
            cout << i;
        }
        cout << endl;
    }
    return 0;
}

/*
40862016542130810467
41000000000000000000
*/