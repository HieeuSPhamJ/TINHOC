#pragma GCC optimize("O2")
#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

set <int> friends[maxN];
map <ii,bool> check;
map <ii,bool> isok;

bool cmp(ii a, ii b){
    return abs(a.fi - a.se) > abs(b.fi - b.se);
}


signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector <ii> fs;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        friends[a].insert(b);
        friends[b].insert(a);
        fs.push_back({a,b});
    }
    for (int i = 1; i <= n; i++){
        friends[i].insert(i);
        fs.push_back({i,i});
    }
    sort(fs.begin(), fs.end(), cmp);

    int ans = 1;

    // cout << (friends[1].find(1) == friends[1].end());

    for (int i = 0; i < fs.size(); i++){
        ii f = fs[i];
        if (check[f] == 1 or f.se - f.fi + 1 <= ans){
            continue;
        }
        int left = f.fi;
        int right = f.se;
        // cout << "With: " << endl;
        // cout << left << " " << right << endl;
        int len = right - left + 1;
        int ok = 1;
        while(left <= right){
            if (isok[{left,right}] == 2){
                break;
            }
            if (isok[{left,right}] == 1){
                ok = 0;
                break;
            }
            if (friends[left].find(right) == friends[left].end()){
                ok = 0;
                isok[{left,right}] = 1;
                break;
            }
            left++;
            right--;
        }

        if (ok){
            check[f] = 1;
            ans = max(ans,len);
            // break;
            while(f.fi <= f.se){
                isok[{f}] = 2;
                f.fi++;
                f.se--;
            }
        }

    }
    cout << ans;
    return 0;
}
