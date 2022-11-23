#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

map <set<ii>,int> store;
int a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = 0;
    for (int j = 1; j <= n; j++){
        // cout << "Index: " << j << endl; 
        set <ii> primes,conv;
        int now = a[j];
        for (int i = 2; i * i <= now; i++){
            if (now % i == 0){
                ii uc = {i,0};
                while(now % i == 0){
                    now /= uc.fi;
                    (uc.se += 1) %= k;
                }
                primes.insert(uc);
                conv.insert({uc.fi, (k - uc.se) % k});
            }
        }
        if (now != 1){
            primes.insert({now,1});
            conv.insert({now, (k - 1) % k});
        }
        
        vector <ii> temp;
        for (auto i: primes){
            if (i.se == 0){
                temp.push_back(i);
            }
        }
        for (auto i: temp){
            primes.erase(i);
        }
        temp.clear();
        for (auto i: conv){
            if (i.se == 0){
                temp.push_back(i);
            }
        }
        for (auto i: temp){
            conv.erase(i);
        }
        // cout << "Primes: " << endl; for (auto i: primes) cout << i.fi << ":" << i.se << endl;
        // cout << "Conv: " << endl; for (auto i: conv) cout << i.fi << ":" << i.se << endl;
        
        // cout << "ans: " << store[conv] << endl;
        // cout << endl;


        ans += store[conv];

        store[primes]++;
    }
    cout << ans << endl;
    return 0;
}