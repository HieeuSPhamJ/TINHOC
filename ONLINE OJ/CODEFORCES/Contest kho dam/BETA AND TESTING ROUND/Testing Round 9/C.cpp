#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 3e5 + 10;

int a[maxN];
int last[30];
map <int,int> res;
signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string ss;
    cin >> ss;
    int n = ss.length();
    for (int i = 1; i <= n; i++){
        a[i] = ss[i - 1] - 'a';
    }
    memset(last,-1,sizeof(last));
    set <int,greater<int>> s;
    s.insert(0);
    for (int i = 1; i <= n; i++){
        // cout << "With: " << i << endl;
        // for (auto x: s){
        //     cout << x << " ";
        // }
        // cout << endl;
        if (s.find(last[a[i]]) != s.end()){
            // cout << "del: " << last[a[i]] << endl;
            s.erase(s.find(last[a[i]]));
        }
        int cnt = 0;
        int la = i;
        for (auto x: s){
            cnt++;
            res[cnt] += la - x;
            // cout << x << " " << la - x << " " << cnt << endl;
            la = x;
        }
        last[a[i]] = i;
        s.insert(i);
    }
    cout << res.size() << endl;
    for (auto i: res){
        cout << i.se << endl;
    }
    return 0;
}