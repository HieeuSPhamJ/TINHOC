#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[(int)2e5 + 10];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> n >> k;
        for (int i = 1, left = 1, right = n; i <= n; i++){
            int t = 0;
            if (i % k){
                t = right;
                right--;
            }
            else{
                t = left;
                left++;
            }
            a[i] = t;
        }
        for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
4 5 1 2 3 
6 6 
*/
