#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[110];

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
            for (int j = i + 1; j <= n; j++){
                if (a[i] == a[j]){
                    cout << "NO" << endl;
                    goto adu;
                }
            }
        }

        for (int i = 2; i <= n; i++){
            map <int,int> temp;
            for (int j = 1; j <= n; j++){
                temp[a[j] % i]++;
            }
            int check = 1;
            int j = i;
            while (j--){
                if (temp[j] < 2){
                    check = 0;
                }
            }
            if (check){
                cout << "NO" << endl;
                goto adu;
            }
        }

        cout << "YES" << endl;
        adu:;
    }
    return 0;
}