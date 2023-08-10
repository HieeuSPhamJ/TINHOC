#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

int a[210];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= 2 * n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n * 2);
        // for (int i = 1; i <= 2 * n; i++){
        //     cout << a[i] << ' ';
        // }
        int check = 1;
        for (int i = 1; i <= n; i++){
            if (abs(a[i] - a[i + n]) < x){
                check = 0;
            }
        }
        if (check == 1){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}