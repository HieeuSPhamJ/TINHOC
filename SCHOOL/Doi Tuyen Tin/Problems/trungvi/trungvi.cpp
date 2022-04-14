#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e7 + 10;

int a[maxN];
int countBigger[maxN];
int countSmaller[maxN];
int diff[maxN];
map <int, int> rightCount;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("trungvi.INP", "r", stdin);
    freopen("trungvi.OUT", "w", stdout);
    int n, m;
    cin >> n >> m;
    int index;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == m){
            index = i;
        }
    }
    countBigger[index] = 0;
    countSmaller[index] = 0;
    for (int i = index; i >= 1; i--){
        countBigger[i] = countBigger[i + 1];
        countSmaller[i] = countSmaller[i + 1];
        if (a[i] < m){
            countSmaller[i]++;
        }
        if (a[i] > m){
            countBigger[i]++;
        }
        diff[i] = countSmaller[i] - countBigger[i];
    }
    for (int i = index + 1; i <= n; i++){
        countBigger[i] = countBigger[i - 1];
        countSmaller[i] = countSmaller[i - 1];
        if (a[i] < m){
            countSmaller[i]++;
        }
        if (a[i] > m){
            countBigger[i]++;
        }
        diff[i] = countSmaller[i] - countBigger[i];
    }
    for (int i = index; i <= n; i++){
        rightCount[diff[i]]++;
    }
    long long count = 0;
    for (int i = 1; i <= index; i++){
        count += (long long)rightCount[-diff[i]];
    }
    cout << count;

    return 0;
}
