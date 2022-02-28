#include<bits/stdc++.h>
using namespace std;

int n;
int countP = 0;

void backTracking(int i, string s){
    if (i > n){
        cout << s << endl;
        countP++;
        return;
    }
    if (s[i - 2] != '0'){
        backTracking(i + 1, s + "0");
    }
    if (s[i - 2] != '1'){
        backTracking(i + 1, s + "1");
    }
    if (s[i - 2] != '2'){
        backTracking(i + 1, s + "2");
    }

}

int main(){
    freopen("DENMAU.INP", "r",stdin);
    freopen("DENMAU.OUT", "w",stdout);
    cin >> n;
    backTracking(1, "");
    cout << countP;
    return 0;

}