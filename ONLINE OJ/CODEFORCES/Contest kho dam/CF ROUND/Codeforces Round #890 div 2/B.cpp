#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];

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
        cin>>n;
        int sum = 0;
        int cnt = 0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cnt += (a[i] == 1);
            if (a[i] != 1){
                sum = sum - a[i] + 1;
            }
        }
        if (sum + cnt <= 0 and n >= 2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}