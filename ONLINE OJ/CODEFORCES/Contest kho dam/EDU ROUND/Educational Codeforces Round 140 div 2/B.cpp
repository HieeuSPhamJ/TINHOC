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
        priority_queue <int, vector <int>, greater <int>> q;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (i > 1){
                q.push(a[i]);
            }
        }

        while(q.empty() == 0){
            int t = q.top();
            q.pop();
            // cout << t << endl;
            if (t > a[1]){
                int sum = t + a[1];
                a[1] = sum - sum / 2;
            }   
        }

        cout << a[1] << endl;
    }
    return 0;
}

/*
1 2 2
1 3 1

*/