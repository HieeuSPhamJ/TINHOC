#include<bits/stdc++.h>
using namespace std;


int n = 6;
vector <int> myVec;
bool check[300] = {0};
int count16 = 0;
int count18 = 0;
int delayCin;

void back(int index, string s){
    if (index > 6){
        int countBinary = 0;
        for (int i = 0; i < 6; i++){
            if (s[i] == '1'){
                countBinary++;
            }
        }
        if (countBinary != 3){
            return;
        }
        int tempSum = 0;
        for (int i = 0; i < 6; i++){
            if (s[i] == '1'){
                tempSum += myVec[i];
                cout << myVec[i] << ' ';
            }
        }
        if (tempSum == 16){
            cout << '!';
        }
        if (tempSum == 18){
            cout << '@';
        }
        cout << endl;
        
        count16 += (tempSum == 16);
        count18 += (tempSum == 18);
    
        return;
    }
    back(index + 1, s + '0');
    back(index + 1, s + '1');
}


bool checkSum(){
    count16 = 0;
    count18 = 0;
    back(1, "");
    cout << count16 << ' ' << count18 << endl;
    if (count16 == 10 and count18 == 10){
        return 1;
    }
    return 0;
}


void backtracking(int index){
    if (index > n){
        for (auto i: myVec){
            cout << i << ' ';
        }
        cout << endl;
        if (checkSum()){
            exit(1);
        }
        return;
    }
    for (int i = 2; i <= 10;i++){
        if (check[i] == 0){
            check[i] = 1;
            myVec.push_back(i);
            backtracking(index + 1);
            check[i] = 0;
            myVec.pop_back();
        }
    }
    

}

int main(){
    freopen("test.txt", "w", stdout);
    backtracking(1);
    return 0;
}
