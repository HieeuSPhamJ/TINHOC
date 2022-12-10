#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        int a[10][10];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                char inp;
                cin >> inp;
                if (inp == 'E'){
                    a[i][j] = 0;
                }
                else{
                    a[i][j] = 1;
                }
            }
        }
        ii check1 = {-1,-1}, check2 = {-1,-1};
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (a[i][j] == 1){
                    check1 = {i, j};
                    break;
                }
            }
            if (check1 != make_pair(-1, -1)){
                break;
            }
        }
        for (int j = 1; j <= m; j++){
            for (int i = 1; i <= n; i++){
                if (a[i][j] == 1){
                    check2 = {i, j};
                    break;
                }
            }
            if (check2 != make_pair(-1, -1)){
                break;
            }
        }

        // cout << check1.f << ',' << check1.s << ' ' << check2.f << ',' << check2.s << endl;

        if (check1 == check2){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}