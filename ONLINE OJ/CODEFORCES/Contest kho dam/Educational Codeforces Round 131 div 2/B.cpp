#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

const int maxN = 2e5 + 10;

int check[maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        cout << 2 << endl;
        int j = 1;
        for (int i = 1; i <= n; i++){
            check[i] = 0;
        }
        for (int i = 1; i <= n; i++){
            for (int j = i; j <= n; j *= 2){
                if (check[j] == 0){
                    cout << j << ' ';
                    check[j] = 1;
                }
            }
        }
        cout << endl;
    }
    return 0;
}