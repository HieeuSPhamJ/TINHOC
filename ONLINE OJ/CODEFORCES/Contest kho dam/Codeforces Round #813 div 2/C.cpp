#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;
int n;
int a[maxN];
int father[maxN];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            father[i] = i;
        }

        if (n == 1){
            cout << 0 << endl;
            continue;
        }

        int right = -1;
        int left = 1;
        int check = 1;
        int ans = 0;

        while (check == 1){
            check = 0;
            for (int i = n; i >= 2; i--){
                if (father[a[i]] >= father[a[i - 1]]){
                    continue;
                }
                check = 1;
                right = i;
                break;
            }
            for (int i = left; i < right; i++){
                if (father[a[i]] == 0){
                    continue;
                }
                ans++;
                father[a[i]] = 0;
            }
            left = right;
        }

        cout << ans;
        cout << endl;
    }
    return 0;
}