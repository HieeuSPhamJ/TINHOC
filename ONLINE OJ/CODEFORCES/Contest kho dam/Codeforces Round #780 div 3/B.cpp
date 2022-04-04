#include<bits/stdc++.h>
using namespace std;

/*

*/


const int maxN = 1e6;

int a[maxN];

bool cmp(int a, int b){
    return a > b;
}

void Solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if (n == 1 and a[1] >= 2){
        cout << "NO";
        return;
    }
    bool check = 0;

    sort(a + 1, a + 1 + n, cmp);
    if (a[1] - a[2] >= 2){
        check = 1;
    }

    if (check == 0){
        cout << "YES";
        return;
    }
    cout << "NO";
}

int main(){
    int test;
    cin >> test;
    while(test--){
        Solve();
        cout << endl;
    }

    return 0;
}
