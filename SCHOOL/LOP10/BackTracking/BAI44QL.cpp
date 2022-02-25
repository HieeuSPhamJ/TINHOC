#include<bits/stdc++.h>
using namespace std;

int n;

void backTracking(int i, string s){
    if (i > n){
        cout << s << endl;
        return;
    }
    backTracking(i + 1, s + "A");
    if (s[i - 2] != 'B'){
        backTracking(i + 1, s + "B");
    }
}

int main(){
    freopen("BAI44QL.INP", "r",stdin);
    freopen("BAI44QL.OUT", "w",stdout);
    cin >> n;
    backTracking(1, "");
    return 0;

}