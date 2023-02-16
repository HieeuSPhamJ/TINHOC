#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 998244353;
const ll base = 31;

ll n ,d;
string s;
ll Hash[500005];
ll Pow[500005];

void HASH(){
    Pow[0] = 1;
    for(int i = 1; i <= n ; i++)Pow[i] = (Pow[i - 1] * base) % MOD;
    for(int i = 1; i <= n ; i++){
        Hash[i] = (Hash[i - 1] * base + s[i] - 'a' + 1) % MOD;
    }
}

ll getHASH(ll i , ll j){
    return (Hash[j] - Hash[i - 1] * Pow[j - i + 1] + MOD * MOD) % MOD;
}

void FRE(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    freopen("KSTRING.inp","r",stdin);
    freopen("KSTRING.out","w",stdout);
}

int main(){
    FRE();
    cin >> n >> d;
    cin >> s;
    s = '0' + s;
    HASH();
    ll  ans[50005];
    map<ll,ll>cnt;
    vector<ll> pre;
    for(int i = 1; i <= n ; i++){
        for(int j = i ; j <= n ; j += i){
            ll res = getHASH(j - i + 1 ,j);
            if(cnt[res] == 0){
                pre.push_back(res);
            }
            cnt[res]++;
        }
        for(int z = 0 ; z < pre.size(); z++){
            ans[i] += cnt[pre[z]] * (cnt[pre[z]] - 1) / 2;
        }
        pre.clear();
    }
    for(int i = 1; i <= n; i++)cout << ans[i] << " ";

    return 0;
}


