#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int mod = 998244353;
const int maxN = 3 * 1e5 + 10;
int fact[maxN];
int infact[maxN];
ii a[maxN];
int newA[2 * maxN];
map <int,int> conv;
int prefixSum[2 * maxN];
int Add[2 * maxN];


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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    // cout << C(5,2) << endl;
    int n, k;
    cin >> n >> k;
    set <int> tempConv;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        tempConv.insert(a[i].fi);
        tempConv.insert(a[i].se);
    }

    int count = 1;
    for (auto i: tempConv){
        conv[i] = count;
        // cout << i << " " << count << endl;
        count++;
    }

    for (int i = 1; i <= n; i++){
        a[i].fi = conv[a[i].fi];
        a[i].se = conv[a[i].se];
        
        Add[a[i].fi] += 1;
        prefixSum[a[i].fi] += 1;
        prefixSum[a[i].se + 1] -= 1;
        // cout << a[i].fi << " " << a[i].se << endl;
    }

    for (int i = 1, temp = 0; i <= 2 * n; i++){
        temp += prefixSum[i];
        newA[i] = temp;
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++){
        int full = 0;
        int temp = 0;
        if (Add[i] > 0 and newA[i] >= k){
            full = C(newA[i],k);
            if (newA[i] - Add[i] >= k){
                temp = C(newA[i] - Add[i],k);
            }
        }
        ans = add(ans, subtr(full, temp));
    }

    cout << ans;

    return 0;
}