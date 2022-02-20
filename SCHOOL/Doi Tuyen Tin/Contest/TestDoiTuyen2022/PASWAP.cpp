#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 10;

int a[maxN];
int sum[maxN];

bool checkEqual(int i, int j){
    long long length = j - i + 1;
    return (((long long) (length + 1) * (long long) length) / 2LL) == (sum[j] - sum[i - 1]); 
}

int main(){
    freopen("PASWAP.INP", "r", stdin);
    freopen("PASWAP.OUT", "w", stdout);
    
    int n;
    cin >> n;
    sum[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        // a[i] = 1;
        sum[i] = sum[i - 1] + a[i];
    }
    int maxLength = 0;
    int indexMax = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            if (checkEqual(i, j)){
                int length = j - i + 1;
                if (length >= maxLength){
                    maxLength = length;
                    indexMax = i;
                }
            }
        }
    }
    if (!maxLength){
        cout << 0;
    }
    else{
        cout << indexMax << endl << maxLength;
    }
    return 0;
}