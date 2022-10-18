#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <int,ii>
#define fi first
#define se second
#define cost fi
#define id se.fi
#define power se.se

#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int ans[maxN];
iii a[maxN];

bool cmp(iii x, iii y){
    return x.power < y.power;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++){
        a[i].id = i;
        cin >> a[i].power;
    }
    
    for (int i = 1; i <= n; i++){
        cin >> a[i].cost;
        ans[i] = a[i].cost;
    }

    sort(a + 1, a + 1 + n, cmp);

    multiset <int> mySet;

    for (int i = 1; i <= n; i++){
        // cout << "Index: " << i << endl;
        if (mySet.empty()){
            mySet.insert(a[i].cost);
            continue;
        }
        auto it = mySet.end();
        it--;
        for (int j = 1; j <= k; j++){
            ans[a[i].id] += *it;
            // cout << *it << " ";
            if (it == mySet.begin()){
                break;
            }
            it--;
        }
        // cout << endl;
        mySet.insert(a[i].cost);
    }

    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}