#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];
int prefix[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            prefix[i] = 0;
        }

        //[m + 1; n]
        for (int i = m + 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + a[i];
        }
        priority_queue <int> q;
        int res = 0;
        for (int i = m + 1, temp = 0; i <= n; i++){
            if (a[i] < 0){
                q.push(-a[i]);
            }
            while(!q.empty() and prefix[i] + temp < 0){
                temp += 2 * q.top();
                q.pop();
                res++;
            }
            // cout << prefix[i] << " " << temp << endl;
        }

        // [1;m]

        for (int i = 1; i <= m; i++){
            prefix[i] = prefix[i - 1] + a[i];
        }

        while(!q.empty()){
            q.pop();
        }

        for (int i = m, temp = 0; i >= 1; i--){
            while(!q.empty() and prefix[i] < prefix[m] + temp){
                temp -= 2 * q.top();
                q.pop();
                res++;
            }
            if (a[i] > 0){
                q.push(a[i]);
            }
        }


        cout << res << endl;
    }
    return 0;
}