#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int maxN = 20;

int a[maxN][maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, test;
    cin >> n >> m >> test;
    for (int i = 0; i < maxN; i++){
        for (int j = 1; j < maxN; j++){
            if ((i & j) > 0){
                a[i][j] = 0;
            }
            else{
                a[i][j] = 1;
            }
            // cout << a[i][j];
        }
        // cout << endl;
    }
    
    while(test--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int count = bool((x1 & y1) == 0);
        for (int i = x1 + 1; i <= x2; i++){
            if ((i & y1) == 0 and (i - 1 & y1) != 0){
                count++;
            } 
        }  
        for (int i = y1 + 1; i <= y2; i++){
            if ((i & x1) == 0 and (i - 1 & x1) != 0){
                count++;
            } 
        }  
        cout << count << endl;
    }



    return 0;
}