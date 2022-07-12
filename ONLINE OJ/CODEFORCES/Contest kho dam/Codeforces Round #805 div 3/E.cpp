#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

bool cmp(ii a, ii b){
    if (a.f == b.f){
        return a.s < b.s;
    }
    return a.f < b.f;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        int check[n + 10] = {0};
        for (int i = 1; i <= n; i++){
            int a, b;
            cin >> a >> b;
            check[a]++;
            check[b]++;
            cout << check[a] << ' ' << check[b] << endl;
            if (check[a] > 2 or check[b] > 2){
                check[0] = 1;
            }
        }

        if (check[0] == 1){
            cout << "NO";
        }
        else{
            cout << "YES";
        }

        cout << endl;
    }
    
    return 0;
}