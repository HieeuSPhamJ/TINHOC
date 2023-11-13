#include"bits/stdc++.h"
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

map <char,char> cv;


int cal(int n){
    return n * (n - 1) / 2 + n;
}

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen("tbrackets.inp", "r")) {
        freopen("tbrackets.inp", "r", stdin);
        freopen("tbrackets.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cv['{'] = '!';
    cv['['] = '!';
    cv['('] = '!';
    cv['<'] = '!';
    cv['}'] = '{';
    cv[']'] = '[';
    cv[')'] = '(';
    cv['>'] = '<';
    
    string s;
    cin >> s;
    int n = s.length();
    s = " " + s;
    int res = 0;
    for (int i = 1; i <= n; i++){
        vector <char> st;
        // cout << "With: " << i << endl;
        for (int j = i; j <= n; j++){
            // cout << j << ":";
            // for (auto i: st){
            //     cout << i;
            // }
            // cout << endl;
            if (cv[s[j]] == '!'){
                // cout << "push" << endl;
                st.push_back(s[j]);
            }
            else{
                if (st.size() and st.back() == cv[s[j]]){
                    // cout << "pop" << endl;
                    st.pop_back();
                }
                else{
                    // cout << "nhu l" << endl;
                    break;
                }
            }
            if (st.size() == 0){
                // cout << i << " " << j << endl;
                res++;
            }
        }

    }

    cout << res << endl;

    return 0;   
}