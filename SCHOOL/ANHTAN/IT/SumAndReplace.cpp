#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3 * 1e5 + 10;
const int inf = 1e18;

int n, test;
int bit[maxN];

void update(int i, int v){
    while(i <= n){
        bit[i] += v;
        i += (i & (-i));
    }
}

int get(int i){
    int res = 0;
    while(i){
        res += bit[i];
        i -= (i & (-i));
    }
    return res;
}

int a[maxN];
int cost[(int)1e6 + 10];
set <int> ls;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        update(i,x);
        ls.insert(i);
        a[i] = x;
    }
    for (int i = 1; i <= 1e6; i++){
        for (int j = i; j <= 1e6; j += i){
            cost[j] += 1;
     
        }
    }

    while(test--){
        int t;
        cin >> t;
        if (t == 1){
            int l, r;
            cin >> l >> r;
            while(1){
                auto it = ls.lower_bound(l);
                if (it == ls.end()){
                    break;
                }
                if (*it > r){
                    break;
                }
                update(*it, -a[*it] + cost[a[*it]]);
                a[*it] = cost[a[*it]];
                l = *it + 1;
                if(a[*it] <= 2){
                    ls.erase(it);
                }
            }
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << get(r) - get(l - 1) << endl;
        }
    }
    
    return 0;
}