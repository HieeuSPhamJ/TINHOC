#include<bits/stdc++.h>
using namespace std;

vector <int> tempVec;
int n;
int a[1000];
int ans = 0;

void Recur(int i){
    if (i == n + 1 and tempVec.size() > 0){
        int tempAns = 1;
        for (int i = 0; i < tempVec.size(); i++){
            tempAns = (tempVec[i] * tempAns) / __gcd(tempVec[i], tempAns);
        }
        ans += tempAns;
    }
    if (i <= n){
        tempVec.push_back(a[i]);
        Recur(i + 1);
        tempVec.pop_back();
        Recur(i + 1);
    }
}


int main(){
    freopen("SPC5.INP", "r", stdin);
    freopen("SPC5.OUT", "w", stdout);
    int test;
    cin >> test;
    while(test--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        tempVec.clear();
        ans = 0;
        Recur(1);
        cout << ans;
        cout << endl;
    }

    return 0;
}