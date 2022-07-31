#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int maxN = 110;

int a[maxN];

signed main(){
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
            int tempA = a[i];
            int m;
            cin >> m;
            // cout << "#" << tempA << endl;
            for (int j = 1; j <= m; j++){
                char inp;
                cin >> inp;
                // cout << inp << ' ';
                if (inp == 'U'){
                    tempA = (tempA + 10 - 1) % 10;
                }
                else{
                    tempA = (tempA + 1) % 10;
                }
                // cout << tempA << endl;
            }
            cout << tempA << ' ';
            // cout << endl;
        }
        cout << endl;
        
    }

    return 0;
}