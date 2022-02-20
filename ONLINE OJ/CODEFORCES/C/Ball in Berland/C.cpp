#include<bits/stdc++.h>
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];
int b[maxN];
int countA[maxN];
int countB[maxN];

int main(){
    int test;
    cin >> test;
    while(test--){
        int numA, numB, k;
        memset(countA, 0, sizeof(countA));
        memset(countB, 0, sizeof(countB));
        cin >> numA >> numB >> k;
        
        for (int i = 1; i <= k; i++){
            cin >> a[i];
            countA[a[i]]++;
        }
        for (int i = 1; i <= k; i++){
            cin >> b[i];
            countB[b[i]]++;
        }
        long long ans = 0;
        for (int i = 1; i <= k; i++){
            ans += k - (countA[a[i]] + countB[b[i]]) + 1;
        }
        cout << ans / 2;
        cout << endl;


    }

    return 0;
}