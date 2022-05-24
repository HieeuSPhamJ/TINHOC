#include<bits/stdc++.h>
using namespace std;

const int maxN = 2 * 1e5 + 10;

int f[maxN];
int maxF[maxN];
int a[maxN];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        f[y] = max(f[y], x);

    }

    for (int i = n; i >= 1; i--){
        maxF[i] = max(maxF[i + 1], f[i]);
    }

    int countDay = 1;
    int j = 1;
    int maxNow = 0;
    for (int i = 1; i <= n; i++){
        // cout << i << ' ' << j << endl;
        if (maxF[1] < a[i]){
            cout << -1;
            return 0;
        }
        if (maxF[j] >= a[i] and maxF[j] >= maxNow){
            j++;
            maxNow = max(maxNow, a[i]);
            
        }
        else {
            j = 1;
            countDay++;
            i--;
            maxNow = 0;
        }
    }

    cout << countDay;


    

    return 0;
}