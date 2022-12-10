#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;


const int maxN = 1e6 + 10;
const int mod = 1000000531;
const int base = 255;

int POW[maxN];


int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}

struct hashtype{
    string data;
    vector <int> ha;
    int len;
    void init(){
        len = data.length();
        ha.resize(len + 3);
        ha[0] = 0;
        for (int i = 0; i < len; i++){
            (ha[i + 1] = ha[i] * base + data[i]) %= mod;
        }
    }
    int getHash(int left, int right){
        return (ha[right] - (ha[left - 1] * POW[right - left + 1]) % mod + mod) % mod;
    }
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    POW[0] = 1;
    for (int i = 1; i <= 1e6 + 7; i++){
        (POW[i] = POW[i - 1] * base) %= mod;
    }

    string s, p;
    getline(cin, s);
    cin >> p;
    
    int k;
    cin >> k;

    hashtype S;
    S.data = s;
    S.init();
    
    hashtype P;
    P.data = p;
    P.init();

    int n = S.len;
    int pn = P.len;

    if (k < pn){
        cout << 0;
        return 0;
    }

    vector <ii> lists;

    for (int i = 1; i + pn - 1 <= n; i++){
        if (S.getHash(i, i + pn - 1) == P.getHash(1, pn)){
            ii seg = {max(1ll,i + pn - k),i};
            if (i + k - 1 > n){
                seg.se = n - k + 1;
            }
            lists.push_back(seg);
        }
    }

    int cnt = 0;
    int last = 0;
    for (auto i: lists){
        if (last < i.fi){
            last = i.fi;
        }
        else if (last >= i.fi){
            last++;
        }
        if (last <= i.se){
            cnt += (i.se - last + 1);
        }
        last = i.se;
        // cout << i.fi << " " << i.se << endl;
        // cout << last << " " << i.se << endl;
    }

    cout << cnt;
    return 0;
}

/*
zzzzzzz
z
xxx
 xxx
  xxx
   xxx
    xxx

*/