#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 50010;

ii a[maxN];

signed main(){
    freopen("Lineup.INP", "r", stdin);
    freopen("Lineup.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set <int> lists;
    for (int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        lists.insert(a[i].se);
    }
    int NUM = lists.size();
    sort(a + 1, a + 1 + n);
    int ans = 1e18;
    int left = 1;
    int right = 1;
    int cnt = 1;
    map <int, int> table;
    table[a[1].se]++;
    while(left <= right and left <= n and right <= n){
        while(cnt < NUM and right <= n){
            right++;
            if (table[a[right].se] == 0){
                cnt++;
            }
            table[a[right].se]++;
        }
        while(cnt > NUM - 1 and left <= right){  
            table[a[left].se]--;
            if (table[a[left].se] == 0){
                cnt--;
            }
            left++;
        }
        left--;
        table[a[left].se]++;
        cnt++;
        if (cnt == NUM){
            ans = min(ans, a[right].fi - a[left].fi);
        }
        right++;
        if (table[a[right].se] == 0){
            cnt++;
        }
        table[a[right].se]++;
    }

    cout << ans << endl;

    return 0;
}

