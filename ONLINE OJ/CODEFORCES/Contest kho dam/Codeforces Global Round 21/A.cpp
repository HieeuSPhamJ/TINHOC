#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

int a[2010];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while (test--){
        int n, z;
        cin >> n >> z;
        int ans = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            ans = max(ans, a[i] | z);
        }
        cout << ans;

        
        cout << endl;
    }
    return 0;
}


/*
    

*/