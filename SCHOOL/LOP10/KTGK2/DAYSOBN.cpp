#include<bits/stdc++.h>
using namespace std;

const int maxN=  1e6 + 10;

int a[maxN];
int countX[maxN];

int main(){
    freopen("DAYSOBN.INP","r", stdin);
    freopen("DAYSOBN.OUT","w", stdout); 
    int n;
    cin >> n;
    int maxNu = 0;
    int maxIndex = 0;
    int maxNum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        maxNum = max(maxNum, a[i]);
        countX[a[i]]++;
    }
    for (int i = 1; i <=  maxNum; i++){
        if (maxNu < countX[i]){
            maxNu = countX[i];
            maxIndex = i;
        }
    }

    for (int i = 1; i <= n; i++){
        if (a[i] == maxIndex){
            cout << i << ' ';
        }
    }
    
    return 0;
}