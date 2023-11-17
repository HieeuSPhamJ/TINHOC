#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int maxN = 1e5 + 10;
int a[maxN];

signed main(){
    freopen("UNORDERED.INP", "r", stdin);
    freopen("UNORDERED.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        int n;
        cin >> n;
        int check1 = 0;
        int check2 = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++){
            if (a[i - 1] < a[i]){
                check1 = 1;
            }
            if (a[i - 1] > a[i]){
                check2 = 1;
            }
        }
        
        if (check1 * check2 == 0){
            cout << 0;
        }
        else{
            cout << 3;
        }


    return 0;
}