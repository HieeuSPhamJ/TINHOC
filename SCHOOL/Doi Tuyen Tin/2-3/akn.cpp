#include<bits/stdc++.h>
using namespace std;

int n, k;
vector <int> vect;
bool check[1000] = {0};

void print(){
    for (int x = 0; x < k; x++){
        cout << vect[x] << ' ';
    }
    cout << '\n';

}

void backTracking(int i){
    if (i > k){
        print();
        return;
    }
    for (int j = 1; j <= n; j++){
        if (check[j] == 0){
            check[j] = 1;
            vect.push_back(j);
            backTracking(i + 1);
            check[j] = 0;
            vect.pop_back();
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("akn.INP", "r", stdin);
    freopen("akn.OUT", "w", stdout);
    cin >> n >> k;
    backTracking(1);
    return 0;
}