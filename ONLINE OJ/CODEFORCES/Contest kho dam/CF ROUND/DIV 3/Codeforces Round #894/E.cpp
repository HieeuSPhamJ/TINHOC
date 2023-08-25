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

int n,m,d;

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        
        cin >> n >> m >> d;

        int res = 0;
        priority_queue <int, vector <int>, greater <int>> q;
        for (int i = 1, t = 0; i <= n; i++){
            int x;
            cin >> x;
            if (x <= 0){
                res = max(res, t - i * d);
                continue;
            }
            if (q.size() < m){
                q.push(x);
                t += x;
                res = max(res, t - i * d);
                continue;
            }
            if (x <= q.top()){
                res = max(res, t - i * d);
                continue;
            }
            t -= q.top();
            t += x;
            q.pop();
            q.push(x);
            res = max(res, t - i * d);
        }
        cout << res << endl;
    }
    return 0;
}