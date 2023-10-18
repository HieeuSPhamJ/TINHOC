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

int n;
int a[maxN];
int cnt[maxN];

void print(){
    for (int i = 1; i <= n; i++){
        cout << cnt[i] << " ";
    }
    cout << endl;
}

void nenso(){
    set <int> s;
    for (int i = 1; i <= n; i++){
        s.insert(a[i]);
    }
    int cnt = 0;
    map <int,int> cv;
    for(auto i: s){
        cnt++;
        cv[i] = cnt;
    }
    for (int i = 1; i <= n; i++){
        a[i] = cv[a[i]];
    }
}



signed main(){
    freopen("SEQUNISS.INP", "r", stdin);
    freopen("SEQUNISS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    nenso();
    for (int i = 1; i <= n; i++){
        cnt[a[i]]++;
    }
    vector <int> ls;
    for (int i = 1; i <= n; i++){
        if (cnt[a[i]] > 1){
            ls.push_back(i);
        }
    }
    if (ls.size() == 0){
        cout << 0 << endl;
        return 0;
    }
    int L = ls.front();
    int R = ls.back();
    // cout << L << " " << R << endl;
    int res = 1e18;
    for (int i = 1; i <= n; i++){
        cnt[i] = 0;
    }
    int l = L;
    int r = R;
    while(1){
        if (r - 1 >= l and cnt[a[r]] == 0){
            cnt[a[r]]++;
            r--;
        }
        else{
            break;
        }
    }
    // cout << l << ' ' << r << endl;
    for (int dup = 0;l <= R; l++){
        while(l > r){
            cnt[a[r + 1]]--;
            if (cnt[a[r + 1]] == 1){
                dup--;
            }
            r++;
        }
        // cout << "With: " << l << " " << r << endl;
        // cout << dup << ": ";
        // print();
        while(dup and r < R){
            cnt[a[r + 1]]--;
            if (cnt[a[r + 1]] == 1){
                dup--;
            }
            r++;
        }
        if (dup == 0){
            // cout << r << endl;
            res = min(res, r - l + 1);
        }
        cnt[a[l]]++;
        // cout << "+" << l << endl;
        if (cnt[a[l]] == 2){
            // cout << "+ dup" << endl;
            dup++;
        }

    }
    cout << res << endl;
    return 0;
}