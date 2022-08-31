#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];
int b[maxN];


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
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }

        for (int i = 1; i <= n; i++) {
            cout << abs(a[i] - b[lower_bound(b + 1, b + n + 1, a[i]) - b]) << " ";
        }
        cout << endl;


        for (int i = 1, j = 1; i <= n; i++) {
            if (i - 1 == j) {
                j++;
            }
            while (a[j + 1] <= b[j] and j < n) {
                j++;
            }
            cout << abs(a[i] - b[j]) << ' ';
        }
        cout << endl;
    }
    return 0;
}