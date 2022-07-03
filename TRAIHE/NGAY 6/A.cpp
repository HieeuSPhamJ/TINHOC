#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

int cal(int n){
    int count = 0;
    for (int i = 1; i * i <= n; i++){
        if (n % i == 0){
            count++;
            if (n / i != i){
                count++;
            }
        }
    }
    return count;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while(cin >> n){
        cout << cal(n) << endl;
    }
    return 0;
}
