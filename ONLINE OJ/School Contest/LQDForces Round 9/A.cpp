#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    map <int,int> cnt;
    for (int i = 1; i <= n; i++){
        char x;
        cin >> x;
        cnt[x]++;
    }

    vector <int> lists;
    
    for (auto i: cnt){
        lists.push_back(i.se);
    }

    sort(rall(lists));
    int res = 0;
    while(lists.size() > k){
        res += lists.back();
        lists.pop_back();
    }

    cout << res << endl;


    return 0;
}