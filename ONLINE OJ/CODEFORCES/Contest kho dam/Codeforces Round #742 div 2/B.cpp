#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int maxN = 1e6;

int xorList[maxN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= 1e6; i++){
        xorList[i] = xorList[i - 1] xor i;
    }

    int test;
    cin>>test;
    while(test--){
    	int a, b;
        cin >> a >> b;
        set <int> lists;
        int fullXor = xorList[a - 1];
        // cout << "###" << endl;
        int n = a;

        // cout << n << ' ' << fullXor << ' ';

        if (fullXor == b){
            cout << n;
        }
        else if (fullXor == 0 and a == b){
            cout << n + 2;
        }
        // else if (fullXor == 0){
        //     cout << n + 1;
        // }
        else{
            cout << n + 1;
        }

        cout << endl;

        
    }
    return 0;
}