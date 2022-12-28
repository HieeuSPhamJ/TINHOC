#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
// #define endl '\n'
#define vec vector <int>
using namespace std;

int n, sum;
double ans;

struct str{
    vec s;
    double cal(){
        double res = 0;    
        vector <double> st;
        for (int i = 0; i < s.size(); i++){
            double d = s[i];
            if (1 <= d and d <= 9){
                st.push_back(d);
            }
            else{
                if (s[i] == '+' or s[i] == '-'){
                    st.push_back(s[i]);
                }
                else if (s[i] == '*'){
                    i++;
                    d = s[i];
                    double last = st.back();
                    st.pop_back();
                    last *= d;
                    st.push_back(last);
                }
                else{
                    i++;
                    d = s[i];
                    double last = st.back();
                    st.pop_back();
                    last /= d;
                    st.push_back(last);
                }
            }
        }
        res = st[0];
        // for (auto x: st){
        //     cout << x << " ";
        // }
        // cout << endl;
        for (int i = 1; i < st.size(); i+=2){
            if ((int)st[i] == '+'){
                res += st[i + 1];
            }
            else{
                res -= st[i + 1];
            }
            // cout << st[i] << " ";
        }
        // cout << endl;
        return res;
    }
};

void adu(int i, vector <int> s){
    
    if (i == 0){
        for (int d = 1; d <= 9; d++){
            vec t;
            t.push_back(d);
            adu(i + 1, t);
        }
        return;
    }
    if (i == n){
        str ss;
        ss.s = s;
        
        if (ss.cal() == sum){
            for (auto x: s){
                if (1 <= x and i <= 9){
                    cout << x;
                    continue;
                }
                cout << char(x);
            }
            cout << endl;
            ans++;
        }
        return;
    }
    
    for (int d = 1; d <= 9; d++){   
        s.push_back('+');
        s.push_back(d);
        adu(i + 1, s);
        s.pop_back();
        s.pop_back();

        s.push_back('-');
        s.push_back(d);
        adu(i + 1, s);
        s.pop_back();
        s.pop_back();

        s.push_back('*');
        s.push_back(d);
        adu(i + 1, s);
        s.pop_back();
        s.pop_back();

        s.push_back('-');
        s.push_back(d);
        adu(i + 1, s);
        s.pop_back();
        s.pop_back();
        
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> sum;
    adu(0,{});
    cout << ans;
    return 0;
}