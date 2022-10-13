#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];
int pre[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }

        for (int i = 1; i <= n; i++){
            a[i] = max(a[i], a[i - 1]);
        }

        while(q--){
            int x;
            cin >> x;
            int left = 1;
            int right = n;
            int ans = 0;
            while(left <= right){
                int mid = (left + right) / 2;
                if (a[mid] > x){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                    ans = pre[mid];
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}