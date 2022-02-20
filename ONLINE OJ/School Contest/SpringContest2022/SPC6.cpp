#include<bits/stdc++.h>
using namespace std;

set <int> checkSet;

int main(){
    freopen("SPC6.INP", "r", stdin);
    freopen("SPC6.OUT", "w", stdout);
    int test;
    cin >> test;
    while(test--){
        checkSet.clear();
        long long n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++){
            long long temp = i * n;
            checkSet.insert(temp % m);
            // cout << temp % m << ' ';
        }
        // cout << endl;
        if (checkSet.size() == m){
            cout << "CORRECT";
        }
        else{
            cout << "INCORRECT";
        }
        cout << endl;
    }

    return 0;
}