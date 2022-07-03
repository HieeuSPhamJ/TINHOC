#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

struct dot{
    int x, y, z;
    dot(int a, b, c){
        x = a;
        y = b;
        z = c;
    }
}

const int mod = 1e9 + 7;
const int maxN = 2 * 1e7 + 100;

long long factor[maxN];

void init(){
    factor[0] = 1;
    for (int i = 1; i < maxN; i++){
        factor[i] = factor[i - 1] * i;
        factor[i] %= mod;
        // cout << factor[i] << endl;
    }

}

long long kCn(long long k, long long n){
    return (factor[n] * fastPow((factor[k] * factor[n - k]) % mod, mod - 2)) % mod;
}

long long cal(dot a, dot b){
    int n = b.x - a.x;
    int m = b.y - a.y;
    int k = b.z - a.z;

    return 

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dot End;
    cin >> End.x >> End.y >> End.z;
    dot floA(x / 3, y / 3, z / 3);
    dot floB(2 * x / 3, 2 * y / 3, 2 * z / 3);
    

    



    return 0;
}