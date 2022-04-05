#include<bits/stdc++.h>
using namespace std;

struct edge{
    int Start;
    int End;
    int Weight;

};

vector <edge> myVec;

bool cmp(edge a, edge b){
    return a.Weight < b.Weight;
}

int main(){
    freopen("CHUYEN01.INP", "r", stdin);
    freopen("CHUYEN01.OUT", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int inp;
            cin >> inp;
            if (inp != 0 and j < i){
            // cout << i << ' ' << j << ' ' << inp << endl;
                edge tempE;
                tempE.Start = min(i, j);
                tempE.End = max(i, j);
                tempE.Weight = inp;
                myVec.push_back(tempE);
            }
        }
    }
    sort(myVec.begin(), myVec.end(), cmp);
    cout << myVec.size() << endl;
    for (auto i: myVec){
        cout << i.Start << ' ' << i.End << ' ' << i.Weight << endl;
    }
    
}