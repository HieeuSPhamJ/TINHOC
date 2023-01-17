#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;
const ii mod = {1000000531,1e9 + 7};
const ii base = {26, 40};
ii POW[maxN];

ii add(ii a, ii b){
    a.fi += b.fi;
    a.se += b.se;
    if (a.fi >= mod.fi){
        a.fi -= mod.fi;
    }
    if (a.se >= mod.se){
        a.se -= mod.se;
    }
    return a;
}

ii mul(ii a, ii b){
    (a.fi *= b.fi) %= mod.fi;
    (a.se *= b.se) %= mod.se;
    return a;
}

ii sub(ii a, ii b){
    (a.fi -= b.fi) += mod.fi;
    (a.se -= b.se) += mod.se;
    if (a.fi >= mod.fi){
        a.fi -= mod.fi;
    }
    if (a.se >= mod.se){
        a.se -= mod.se;
    }
    return a;
}

struct hashtype{
    string data;
    ii ha[maxN];
    int len;
    void init(){
        len = data.length();
        ha[0] = {0,0};
        for (int i = 0; i < len; i++){
            ha[i + 1] = add(mul(ha[i], base), sub({data[i], data[i]}, {'a','a'}));
        }
    }
    ii getHash(int left, int right){
        return sub(ha[right], mul(ha[left - 1], POW[right - left + 1]));
    }
};

signed main(){
    freopen("D561077.INP", "r", stdin);
    freopen("D561077.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    POW[0] = {1,1};
    for (int i = 1; i < maxN; i++){
        POW[i] = mul(POW[i - 1], base);
    }
    int n;
    cin >> n;
    hashtype s;
    cin >> s.data;
    s.init();

    // cout << s.getHash(2,4) << " " << s.getHash(9,11) << endl;

    int left = 0;
    int right = n - 1;
    int ans = -1;
    unordered_set <int> cnt;
    while(left <= right){
        int mid = (left + right) / 2;
        cnt.clear();
        int ok = 0;
        for (int i = 1; i + mid <= n; i++){
            ii now =  s.getHash(i, i + mid);
            int hashnow = now.se | (now.fi << 30);
            if(!cnt.insert(hashnow).second){
                ok=true;
                break;
            }
        }

        if (ok){
            left = mid + 1;
            ans = mid;
        }
        else{
            right = mid - 1;
        }
    }

    cout << ans + 1;

    return 0;
}