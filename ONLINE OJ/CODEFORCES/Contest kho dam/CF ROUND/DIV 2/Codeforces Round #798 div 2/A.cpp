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
        char a[110];
        char b[110];
        
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < m; i++){
            cin >> b[i];
        }
        
        sort(a, a + n);
        sort(b, b + m);

        // cout << a << ' ' << b << endl;

        string c = "";
        int i = 0;
        int j = 0;
        int len = n + m;

        int turn = 0;
        int last = -1;

        while(len--){
            if (i >= n){
                i++;
                turn++;
                c += b[i];
                if (last != 2){
                    turn = 1;
                }
                last = 2;
            }
            if (i >= m)
            if (a[i] < b[j]){
                i++;
                turn++;
                c += a[i];
                if (last != 1){
                    turn = 1;
                }
                last = 1;
            }
            else{
                j++;
                turn++;
                c += b[j];
                if (last != 2){
                    turn = 1;
                }
                last = 2;
            }
        }   
        cout << c;
    }

    return 0;
}