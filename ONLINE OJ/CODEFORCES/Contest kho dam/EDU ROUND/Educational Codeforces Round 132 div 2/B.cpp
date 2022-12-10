#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int dpLR[maxN];
int dpRL[maxN];


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dpLR[1] = 0;

    for (int i = 2; i <= n; i++){
        int temp = 0;
        if (a[i - 1] - a[i] > 0){
            temp = a[i - 1] - a[i];
        }
        dpLR[i] = dpLR[i - 1] + temp;
    }

    dpRL[n] = 0;

    for (int i = n - 1; i >= 1; i--){
        int temp = 0;
        if (a[i + 1] - a[i] > 0){
            temp = a[i] - a[i + 1];
        }
        dpRL[i] = dpRL[i + 1] + temp;
    }

    // for (int i = 1; i <= n; i++){
    //     cout << dpLR[i] << ' ';
    // }
    // cout << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << dpRL[i] << ' ';
    // }
    // cout << endl;

    while(test--){
        int a, b;
        cin >> a >> b;
        // cout << dp[a]
        if (a < b){
            cout << dpLR[b] - dpLR[a];
        }
        else{
            cout << dpRL[a] - dpRL[b];
            // cout << '-';
        }
        cout << endl;
    }
    return 0;
}