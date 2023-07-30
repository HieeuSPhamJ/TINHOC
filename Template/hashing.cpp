#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;
const ii mod = {1e9 + 7, 1e9 + 9};
const ii base = {50,24};
 
ii POW[maxN];
 
ii mul(ii a, ii b){
    (a.fi *= b.fi) %= mod.fi;
    (a.se *= b.se) %= mod.se;
    return a;
} 
 
ii add(ii a, ii b){
    (a.fi += b.fi) %= mod.fi;
    (a.se += b.se) %= mod.se;
    return a;
}
 
 
ii subtr(ii a, ii b){
    (a.fi = a.fi - b.fi + mod.fi) %= mod.fi;
    (a.se = a.se - b.se + mod.se) %= mod.se;
    return a;
}
 
struct hashtype{
    vector <char> s;
    vector <ii> ha;
    vector <int> turn;
    int len(){
        return s.size() - 1;
    }
    void init(string s0){
        int l = s0.length();
        s.push_back(' ');
        ha.push_back({0,0});
        turn.push_back(0);
        for (int i = 0; i < l; i++){
            s.push_back(s0[i]);
            ha.push_back(add(mul(ha[i], base), {s0[i], s0[i]}));
        }
    }
    void push(char c){
        s.push_back(c);
        ha.push_back(add(mul(ha.back(), base), {c,c}));
    }
    void pop(){
        turn.pop_back();
        s.pop_back();
        ha.pop_back();
    }
    ii get(int l, int r){
        if (r > len()){
            return {-1,-1};
        }
        return subtr(ha[r], mul(ha[l - 1], POW[r - l + 1]));
    }
};

void print(ii x, char c = endl){
    cout << x.fi << ' ' << x.se << c;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    POW[0] = {1,1};
    for (int i = 1; i < maxN; i++){
        POW[i] =  mul(POW[i - 1], base);
    }

    int n, m;
    string s;
    cin >> n >> s;
    hashtype a, b;
    a.init(s);
    
    return 0;
}
