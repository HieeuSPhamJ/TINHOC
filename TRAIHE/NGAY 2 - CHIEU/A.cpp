#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

map <string, int> convert;
map <int, string> reConvert;

void init(){
    convert["Red"] = 0;
    convert["Orange"] = 1;
    convert["Yellow"] = 2;
    convert["Green"] = 3;
    convert["Blue"] = 4;
    convert["Violet"] = 5;

    reConvert[0] = "Red";
    reConvert[1] = "Orange";
    reConvert[2] = "Yellow";
    reConvert[3] = "Green";
    reConvert[4] = "Blue";
    reConvert[5] = "Violet";
}

int plu(int n){
    return(n + 1) % 6;
}

int minu(int n){
    return(n - 1 + 6) % 6;
}

int cov(int n){
    return n % 6;
}

int main(){
    freopen("color.inp", "r", stdin);
    freopen("color.out", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    string s1, s2;
    cin >> s1 >> s2;

    int a = convert[s1];
    int b = convert[s2];

    if (a == b){
        cout << "Same";
    }
    else if (a == plu(b) or plu(a) == b){
        cout << "Adjacent";
    }
    else if (plu(a) == minu(b)){
        cout << reConvert[(a + 1) % 6];
    }
    else if (plu(b) == minu(a)){
        cout << reConvert[(b + 1) % 6];
    }
    else if (abs(a - b) == 3){
        cout << "Complementary";
    }
    else{
        cout << "None";
    }
    

    // cout << minu(0);


    return 0;
}