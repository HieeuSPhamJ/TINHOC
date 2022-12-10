#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];
int maxL[maxN];
int maxR[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        unordered_map <int, int> check;
        for (int i = 1; i <= n; i++){
            
            cin >> a[i];
        }
        for (int i = 0; i <= n + 2; i++){
            maxL[i] = 0;
            maxR[i] = 0;
        }
        if (n == 1 or n == 2){
            cout << "YES";
            cout << endl;
            continue;
        }
        int ans = 0;

        maxR[n] = a[n];
        maxL[1] = a[1];
        for (int i = n - 1; i >= 1; i--){
            maxR[i] = max(a[i], maxR[i + 1]);
        }
        for (int i = 2; i <= n; i++){
            maxL[i] = max(a[i], maxL[i - 1]);
        }
        for (int i = 2; i < n; i++){
            if (maxL[i - 1] > a[i] and a[i] < maxR[i + 1]){
                ans = 1;
            }
        }

        if (ans == 0){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}