#include<bits/stdc++.h>
using namespace std;

int a[110];

int main(){
    int n;
    cin >> n;
    int m, k;
    cin >> m >> k;
    int minTree = 1e9;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        minTree = min(minTree, a[i]);
    }
    
    

    return 0;
}