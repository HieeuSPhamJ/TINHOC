#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e4;

int check[maxN];

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        for (int i = 0; i < maxN; i++){
            check[i] = 0;
        }
        int n;
        cin >> n;
        int count = 0;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            if (check[inp] == 0){
                count++;
            }
            check[inp]++;
        }
        if (n % 2 != count % 2){
            count--;
        }
        cout << count;
        cout << endl;
    }
    

    return 0;
}


