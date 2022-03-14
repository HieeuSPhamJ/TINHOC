#include<bits/stdc++.h>
using namespace std;

int n;
vector <int> vect;
bool check[1000] = {0};

void print(){
    for (int x = 0; x < n; x++){
        cout << vect[x] << ' ';
    }
    cout << '\n';

}

void backTracking(int i){
    if (i > n){
        print();
        return;
    }
    for (int j = 1; j <= n; j++){
        if (check[j] == 0 and j != i){
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
    freopen("HVTT.INP", "r", stdin);
    freopen("HVTT.OUT", "w", stdout);
    cin >> n;
    backTracking(1);
    return 0;
}