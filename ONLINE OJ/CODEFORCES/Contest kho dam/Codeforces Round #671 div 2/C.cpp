#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 1010;

int n, x;
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
        
        cin >> n >> x;
        int count = 0;
        int sumt = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            sumt += x - a[i];
            if (x == a[i]){
                count++;
            }
        }
        if (count == n){
            cout << 0 << endl;
        }
        else if (sumt == 0 or (count >= 1 and count < n)){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
    return 0;
}