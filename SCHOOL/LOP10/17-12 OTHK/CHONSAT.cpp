#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000006];

bool cmp( int a, int b){
    return (a > b);
}

int main() {
    freopen( "CHONSAT.INP", "r", stdin);
	freopen( "CHONSAT.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort (a + 1, a + n + 1, cmp);
    int maxAns  = -1;
    int maxCount = -1;
    for (int i = 1; i <= n; i++){
        int count = 1;
        while (a[i + 1] == a[i]){
            i++;
            count++;
        }
        if  (count > maxCount){
            maxAns = a[i];
            maxCount = count;
        }
    }
    cout << maxCount << endl << maxAns;

}