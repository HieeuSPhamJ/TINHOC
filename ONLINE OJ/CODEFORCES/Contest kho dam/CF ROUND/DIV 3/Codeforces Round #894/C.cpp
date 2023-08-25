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
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        deque <int> ls;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;
            ls.push_back(x);
        }
        int t = 0;
        int ok = 1;
        while(ls.size()){
            if (ls.size() == 1 and ls.back() == 1){
                break;
            }
            if (ls.front() - t != ls.size()){
                ok = 0;
                break;
            }
            ls.pop_front();
            t++;
            while (ls.size() and ls.back() == t){
                ls.pop_back();
            }
        }
        if (ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}