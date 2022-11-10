#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
const int mod = 1e9 + 7;

ii a[maxN];

int fact[maxN];
int infact[maxN];

int add(int a, int b){
    return (a + b) % mod;
}
int subtr(int a, int b){
    return ((a + mod) - b) % mod; 
}
int mul(int a, int b){
    return (a * b) % mod;
}
int fastpow(int n, int a){
    if (a == 0){
        return 1;
    }
    if (a == 1){
        return n;
    }
    int temp = fastpow(n, a / 2);
    int ans = mul(temp, temp);
    if (a % 2){
        return mul(ans, n);
    }
    else{
        return ans;
    }
}
void init(){
    fact[0] = 1;
    for (int i = 1; i < maxN; i++){
        fact[i] = mul(fact[i - 1], i);
    }
    infact[maxN - 1] = fastpow(fact[maxN - 1], mod - 2);
    for (int i = maxN - 2; i >= 0; i--){
        infact[i] = mul(infact[i + 1], i + 1);
    }
    
}
int C(int n, int k){
    return mul(fact[n], mul(infact[k], infact[n - k]));
    return mul(fact[n], fastpow(mul(fact[k], fact[n - k]), mod - 2));
}

int mind(ii x){
    return min(x.fi - x.se, x.se - 1);
}

bool cmp(ii x, ii y){
    return (mind(x) > mind(y));
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i].se;
    }

    int ans = 0;

    vector <int> lists;

    for (int i = 1; i <= n; i++){
        lists.push_back(mind(a[i]));
        ans = add(ans,a[i].fi - 1);
    }
    sort(lists.rbegin(), lists.rend());
    int cnt = 0;
    // cout << ans << endl;
    // for (auto i: lists){
    //     cout << i << " ";
    // }
    // cout << endl;

    while(lists.back() == 0 and !lists.empty()){
        lists.pop_back();
    }
    int lastVal = 0;
    while(!lists.empty()){
        int val = lists.back();
        ans = add(ans, abs(lastVal - val) * fastpow(2,(int)lists.size()));
        // cout << (int)lists.size() << endl;
        while(lists.back() == val and !lists.empty()){
            lists.pop_back();
        }
        lastVal = val;
    }

    cout << ans;

    // cout << fastpow(2,1e5); 
    return 0;
}