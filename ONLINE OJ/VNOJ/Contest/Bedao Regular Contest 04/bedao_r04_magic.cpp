#include<bits/stdc++.h>
using namespace std;

map <int,int> check;
int a[2000006];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        check[a[i]]++;
    }
    long long ans = 0;
    for (int x = 1; x <= n - 3; x++){
    for (int y = x + 1; y <= n - 2; y++){
    for (int z = y + 1; z <= n - 1; z++){
    for (int w = z + 1; w <= n; w++){
        int c = a[x] + a[y] + a[z] + a[w];
        if (c == 0){
            ans++;
        }
    }
    }
    }
    }
    cout << ans;


    return 0;
}