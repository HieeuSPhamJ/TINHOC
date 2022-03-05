#include<bits/stdc++.h>
using namespace std;

const int maxN = 100010;

int n, m;
int a[maxN];


int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    // for (int i = 0; i < n; i++){
    //     cout << a[i] << ' ';
    // }
    int price = 0;
    int index = 0;
    while(index < n and price + a[index] <= m){
        price += a[index];
        // cout << a[index] << ' ';
        index++;
    }

    cout << index;
    return 0;
}