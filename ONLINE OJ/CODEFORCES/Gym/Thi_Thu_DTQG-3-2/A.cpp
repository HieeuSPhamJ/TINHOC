#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> ls;
    int sum = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        ls.push_back(x);
        sum += x;
    }
    sort(all(ls));
    int l = -1;
    int r = n;
    int res = 0;
    // for (auto i: ls){
    //     cout << i << " ";
    // }
    // cout << endl;
    while(1){
        while(sum > 0){
            r--;
            sum -= ls[r];
            res++;
        }
        if (sum < 0){
            l++;
            sum -= ls[l];
            res++;
        }
        else{
            cout << res;
            return 0;
        }
    }

    return 0;
}