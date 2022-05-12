#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int prefixSum[maxN];

int main(){
    int n;
    cin >> n;
    int m, k;
    cin >> m >> k;
    int w = m;
    int minTree = 1e9;
    int indexTree = 1;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (minTree > a[i]){
            minTree = a[i];
            indexTree = i;
        }
    }
    int index = indexTree;
    if (indexTree - m <= 0){
        indexTree = 1;
    }
    else{
        indexTree -= k;
    }
    for (int i = indexTree; i <= n; i++){
        if (m <= 0){
            break;
        }
        m--;
        prefixSum[i] += w;
        prefixSum[i + 1 + k + k] += -w;
        i += 1 + k;
    }
    int temp = 0;
    for (int i = 1; i <= n; i++){
        temp += prefixSum[i];
        a[i] += temp;
        cout << a[i] << ' ';
    }
    cout << a[index];
    return 0;
}