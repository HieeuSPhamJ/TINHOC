#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 3 * 1e5 + 10;

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
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int count = 0;
        for (int i = 1; i <= n;){
            // cout << i << " ";
            if (i == n){
                break;
            }
            int j = i + 1;
            if (a[i] > a[j]){
                while(a[i] > a[j] and j < n){
                    j++;
                }
                count++;
            }
            else{
                while(a[i] < a[j] and j < n){
                    j++;
                }
                count++;
            }
            i = j;
        }
        cout << count << endl;
    }

    return 0;
}