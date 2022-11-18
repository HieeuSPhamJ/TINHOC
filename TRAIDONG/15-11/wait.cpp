#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define all(x) x.begin(),x.end()
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int n, m;
int ans[maxN];
deque <ii> shop;
deque <ii> tourist;

void sub1(){
    for (auto t: tourist){
        int ts = t.fi;
        int ans = 1e18;
        for (auto s: shop){
            if (ts <= s.fi){
                ans = min(ans, abs(s.fi - ts));
            }
            else{
                if (ts <= s.se){
                    ans = min(ans, 0ll);
                }
            }
            if (ans == 0){
                break;
            }
        }
        if (ans == 1e18){
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
}

void sub2(){
    sort(all(tourist));
    sort(all(shop));
    // for (auto i: tourist){
    //     cout << i.fi << " ";
    // }
    // cout << endl;
    // for (auto i: shop){
    //     cout << i.fi << " " << i.se << endl;
    // }
    // cout << endl;
    set <int> now;
    for (auto i: tourist){
        int ts = i.fi;
        // cout << "With: " << ts << endl;
        vector <int> remo;
        for (auto s: now){
            if (s >= ts){
                break;
            }
            remo.push_back(s);
        }
        for (auto s: remo){
            now.erase(now.find(s));
        }
        while(shop.front().fi <= ts and !shop.empty()){
            if (shop.front().se >= ts){
                now.insert(shop.front().se);
            }
            shop.pop_front();
        }
        // for (auto i: now){
        //     cout << i << " ";
        // }
        // cout << endl;
        if (now.empty()){
            if (shop.empty()){
                ans[i.se] = -1;
                continue;
            }
            ans[i.se] = abs(shop.front().fi - ts);
            continue;
        }
        ans[i.se] = 0;
    }

    for (int i = 1; i <= m; i++){
        cout << ans[i] << endl;
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        ii s;
        cin >> s.fi >> s.se;
        s.se--;
        shop.push_back(s);
    }

    for (int i = 1; i <= m; i++){
        int s;
        cin >> s;
        tourist.push_back({s,i});
    }
    // if (n * m <= 1e7){
    //     sub1();
    //     return 0;
    // }
    sub2();
    return 0;
}