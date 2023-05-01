#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000];

void cal(){
    int I, J, Res = 1e8;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] + a[j] < Res){
                Res = a[i] + a[j];
                I = i;
                J = j;
            }   
        }
    }
    cout << Res << " " << I << " " << J << endl;
}

signed main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cal();
    return 0;
}

