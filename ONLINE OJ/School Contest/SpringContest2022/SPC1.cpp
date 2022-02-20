#include<bits/stdc++.h>
using namespace std;


vector <long long> myVector;
vector <long long> newVector;

void add(long long n){
    newVector.clear();
    int len = myVector.size();
    int check = 0;
    if (myVector.empty()){
        myVector.push_back(n);
    }
    else{
        for (int i = 0; i < len; i++){
            if (n <= myVector[i] and check == 0){
                newVector.push_back(n);
                check = 1;
            }
            newVector.push_back(myVector[i]);
        }
        if (check == 0){
            newVector.push_back(n);
        }
        myVector.swap(newVector);
    }
    // for (int i = 0; i < myVector.size(); i++){
    //     cout << myVector[i] << ' ';
    // }
    // cout << "*" << endl;
}


int main(){
    freopen("SPC1.INP", "r", stdin);
    freopen("SPC1.OUT", "w", stdout);
    int test;
    cin >> test;
    while(test--){
        int qe;
        cin >> qe;
        myVector.clear();
        while(qe--){
            int q;
            cin >> q;
            long long inp;
            cin >> inp;
            if (q == 1){
                add(inp);
            }
            else{
                cout << myVector[inp - 1];
                cout << endl;
            }
        }

    }



    return 0;
}