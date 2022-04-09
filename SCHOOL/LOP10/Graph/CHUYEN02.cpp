#include<bits/stdc++.h>
using namespace std;

vector <int> countVect;
vector <int> adj;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("CHUYEN02.INP", "r", stdin);
    // freopen("CHUYEN02.OUT", "w", stdout);
    int n;
    cin >> n;
    int count =  0;
    for (int i = 1; i <= n; i++){
        countVect.push_back(count);
        for (int j = 1; j <= n; j++){
            int inp;
            cin >> inp;
            if (inp){
                count++;
                adj.push_back(j);
            }
        }
    }
    countVect.push_back(count);
    for (auto i: countVect){
        cout << i << ' ';
    }
    cout << endl;
    for (auto i: adj){
        cout << i << ' ';
    }
    return 0;
}