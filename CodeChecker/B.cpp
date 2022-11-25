#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 2010;

int a[maxN];

signed main(){
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int d;
    cin >> d;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    
    // for (int i = 1; i <= n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    int ans = 1;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            int left = i + 1;
            int right = j - 1;
            int root = a[i] + a[j];
            int tans = 1;
            // cout << "With: " << i << " " << j << endl;
            while(left < right){
                while(a[left] + a[right] != root){
                    while(left < right and root < (a[left] + a[right])){
                        right--;
                    }
                    if (left == right){
                        goto bru;
                    }
                    while(left < right and root > (a[left] + a[right])){
                        left++;
                    }
                    if (left == right){
                        goto bru;
                    }
                
                }   
                // cout << left << " " << right << endl;
                tans++;
                left++;
                right--;
            }
            bru:;
            ans = max(ans, tans);
        }
    }
    cout << ans;
    return 0;
}

/*
1 2 3 4 5 6 7 8
1 1 3 3 4 6 8 9 

*/
