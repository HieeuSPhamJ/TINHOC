#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e6 + 10;

int a[maxN];

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        int count = 0;
        if (a[i] != 1){
            for (int x = 1; x < n; x++){
                if (x == i){
                    continue;
                }
                for (int y = x + 1; y <= n; y++){
                    if (y == i){
                        continue;
                    }
                    int gcd = __gcd(a[x], a[y]);
                    if ((gcd / a[i]) % 2 == 0 and gcd % a[i] == 0){
                        count++;
                    }
                }
            }

        }
        else{
            for (int x = 1; x < n; x++){
                if (x == i){
                    continue;
                }
                for (int y = x + 1; y <= n; y++){
                    if (y == i){
                        continue;
                    }
                    int gcd = __gcd(a[x], a[y]);
                    if (gcd % 2 == 0){
                        count++;
                    }
                }
            }
        }
        
        cout << count << ' ';
    }
    



    return 0;
}