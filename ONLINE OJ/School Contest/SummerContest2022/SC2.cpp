#include<bits/stdc++.h>
using namespace std;

const int maxN = 100010;

int setupArr[maxN];

void setup(){
    int count = 1;
    for (int i = 1; count <= maxN; i++){
        if (!(i % 3) or !(i % 5) or !(i % 7)){
            setupArr[count] = i;
            count++;
        }
    }

}

int main(){
    freopen("SC2.INP", "r", stdin);
    freopen("SC2.OUT", "w", stdout);

    setup();
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        cout << setupArr[n];
        cout << endl;
    }

    return 0;
}