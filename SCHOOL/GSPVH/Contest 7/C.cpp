#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 2e5 + 10;

int a[maxN];

signed main(){
    //freopen("winterfashion.INP", "r", stdin);
    //freopen("winterfashion.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    int total = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = (a[i] < 20);
        total += a[i];
        // cout << a[i];
    }
    // cout << endl;
    if (total == n){
        if (k < n){
            cout << -1 << endl;
        }
        else{
            cout << 1 << endl;
        }
        return 0;
    }
    if (total == 0){
        cout << 0 << endl;
        return 0;
    }
    a[n + 1] = 1;
    multiset <int> s;
    int en = -1;
    for (int i = 1, la = 0; i <= n + 1; i++){
        if (a[i]){
            if (la != 0 and la + 1 != i){
                if (i == n + 1){
                    en = i - la - 1;
                }
                s.insert(i - la - 1);
                // cout << i << " ";
                // cout << i - la - 1 << endl;
            }
            la = i;
        }
    }

    int cover = n;
    for (int i = 1; i <= n; i++){
        if (a[i]){
            break;
        }
        cover--;
    }
    

    int res = 1;
    while(s.size() and cover > k){
        auto t = s.end();
        t--;
        if (s.find(en) != s.end() and cover - en <= k){
            cover -= en;
            res++;
            break;
        }
        res += 2;
        cover -= *t;
        if (en == *t){
            s.erase(t);
            if (s.find(en) == s.end()){
                res--;
            } 
        }
        else{
            s.erase(t);
        }
        // cout << *t << endl;  
    }

    if (cover > k){
        cout << -1 << endl;
        return 0;
    }

    cout << res << endl;

    return 0;
}
/*
20 19 20 20 20 
*/