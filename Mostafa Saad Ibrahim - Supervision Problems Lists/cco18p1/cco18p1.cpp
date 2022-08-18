#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

struct game{
    char result;
    int point;
};

const int maxN = 1e3 + 10;

game a[maxN];
game b[maxN];
int dpAwin[1010];
int dpBwin[1010];    

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].result;
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i].point;
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i].result;
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i].point;
    }
    
    vector <int> A[3];
    vector <int> B[3];

    for (int i = 1; i <= n; i++){
        if (a[i].result == 'W'){
            A[1].push_back(a[i].point);
        }
        else{
            A[0].push_back(a[i].point);    
        }
    }
    for (int i = 1; i <= n; i++){
        if (b[i].result == 'W'){
            B[1].push_back(b[i].point);
        }
        else{
            B[0].push_back(b[i].point);    
        }
    }

    sort(A[0].begin(), A[0].end());
    sort(A[1].begin(), A[1].end());
    sort(B[0].begin(), B[0].end());
    sort(B[1].begin(), B[1].end());

    for (int i = 0; i <= 1; i++){
        cout << i << ": ";
        for (auto j: A[i]){
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << "------" << endl;
    for (int i = 0; i <= 1; i++){
        cout << i << ": ";
        for (auto j: B[i]){
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl;

    if (!B[0].empty()){
        for (int i = 0; i < (int)A[1].size(); i++){

        }   
    }


    if (!A[0].empty()){
        for (int i = 0; i < (int)B[1].size(); i++){

        }   
    }
    return 0;
}