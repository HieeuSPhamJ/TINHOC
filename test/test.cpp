#include<bits/stdc++.h>
using namespace std;

map <int, map <int, long long>> prefix;\

int calLen(int ix, int iy, int x, int y){
    return ceil(sqrt(pow(ix - x, 2) + pow(iy - y, 2)));
}

int main(){
    cout <<
}