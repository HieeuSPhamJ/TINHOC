#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

const int maxN = 50;

int a[maxN][maxN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i <= maxN; i++){
        cout << i << ' ';
        if (i < 10){
            cout << " ";
        }
        for (int j = 0; j <= maxN; j++){
            if ((i & j) > 0){
                cout << " ";
            }
            else{
                cout << "O";
            }
            // cout << (i & j) << ' ';
        }
        cout << endl;
    }




    return 0;
}