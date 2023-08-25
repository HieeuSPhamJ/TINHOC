#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5010;
const ii mod = {1e9 + 7, 1e9 + 9};

int a[maxN];
int dp[maxN][maxN];
int pre[maxN][maxN];

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
    hashtype ha;
    ha.init("");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        a[i] = x - '0';
        ha.push(x);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        pre[0][i] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int k = 1; i - k >= 0; k++){
            if (a[i - k + 1] == 0){
                dp[i][k] = 0;
                continue;
            }
            int j = i - k;
            int g = k;
            int l = 0;
            int r = k - 1;
            int len = 0;
            if (j - k + 1 >= 1){
                while(l <= r){
                    int mid = (l + r) / 2;
                    if (ha.get(j - k + 1, j - k + 1 + mid) == ha.get(i - k + 1, i - k + 1 + mid)){
                        l = mid + 1;
                        len = mid + 1;
                    }
                    else{
                        r = mid - 1;
                    }
                }
                if (len == k or a[j - k + 1 + len] > a[i - k + 1 + len]){
                    g--;
                }
            }
            // cout << "With: " << i << " " << k << endl;
            // cout << j << " " << g << " "  << len << endl;
            dp[i][k] = pre[j][g];
        }
        for (int j = 1; j <= n; j++){
            (pre[i][j] = pre[i][j - 1] + dp[i][j]) %= mod.fi;
        }
    }

    
    // for (int j = 0; j <= n; j++){
    // for (int i = 0; i <= n; i++){
    //     cout << dp[i][j] << " ";
    // }   
    // cout << endl;
    // }

    cout << pre[n][n] << endl;
    return 0;
}

/*
1 2 3 4 3 4
 
*/