#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define high fi
#define at se.fi
#define id se.se
#define iii pair <int,ii>
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e4 + 10;

iii a[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set <iii> s;
    for (int i = 1; i <= n; i++){
        cin >> a[i].at >> a[i].high;
        a[i].id = i;
        s.insert(a[i]);
    }
    int ans = 0;
    while(s.size()){
        iii t = *s.rbegin();
        s.erase(t);
        int mid = t.id;
        ans++;
        // cout << "With: " << t.at << " " << t.high << endl;
        for (int k = 0; mid - k >= 1; k++){
            int j = mid - k;
            if (abs(t.at - a[j].at) <= t.high - a[j].high){
                if (s.find(a[j]) != s.end()){
                    // cout << k << " " << j << " ";
                    // cout << a[j].at << " " << a[j].high << endl;
                    s.erase(a[j]);
                }
            }
        }
        
        for (int k = 0; mid + k <= n; k++){
            int j = mid + k;
            if (abs(t.at - a[j].at) <= t.high - a[j].high){
                if (s.find(a[j]) != s.end()){
                    // cout << a[j].at << " " << a[j].high << endl;
                    s.erase(a[j]);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}