#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

const int maxN = 5 * 1e5 + 10;

int numKids[maxN];
int father[maxN];

int checkFather(int kid){
    if (kid == father[kid]){
        return kid;
    }
    return father[kid] = checkFather(father[kid]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, test;
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        father[i] = i;
        numKids[i] = 1;
    }
    while(test--){
        char q;
        cin >> q;
        if (q == '+'){
            int a, b;
            cin >> a >> b;
            int A = checkFather(a);
            int B = checkFather(b);
            if (A == B){
                continue;
            }
            if (numKids[A] > numKids[B]){
                numKids[A] += numKids[B];
                father[B] = A;
            }
            else{
                numKids[B] += numKids[A];
                father[A] = B;
            }
        
        }
        else{
            int a;
            cin >> a;
            cout << numKids[checkFather(a)] << endl;
        }

    }

    return 0;
}