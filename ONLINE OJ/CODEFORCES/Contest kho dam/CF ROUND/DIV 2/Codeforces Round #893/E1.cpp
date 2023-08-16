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
    vector <int> ls;
    map <int,int> cnt;
    set <int> s;
    int ans = 0;
    while(test--){
        char c;
        cin >> c;
        if (c == '+'){
            int x;
            cin >> x;
            ls.push_back(x);
            s.insert(x);
            if (cnt[x] == 0){
                ans++;
            }
            cnt[x]++;

        }
        else if (c == '-'){
            int x;
            cin >> x;
            while(x--){
                int t = ls.front();
                ls.pop_back();
                cnt[t]--;
                if (cnt[t] == 0){
                    ans--;
                }
            }
        }
        else
    }
    return 0;
}