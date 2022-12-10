#include<bits/stdc++.h>
using namespace std;

long long a[30];
long long b[30];
int n;



int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }
        long long ans = 0;
        for (int i = 1; i < n; i++){
            ans=ans+min(abs(a[i]-a[i+1])+abs(b[i]-b[i+1]),abs(b[i]-a[i+1])+abs(a[i]-b[i+1]));

        }
        cout << ans;
        cout << '\n';

    }

    return 0;
}