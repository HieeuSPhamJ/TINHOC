#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int mod = 1e9 + 7;
const int maxN = 255;
const int maxLen = 1e6 + 10;

int countChar[maxN];



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    char inp;
    int minChar = 1e9;
    int maxChar = 0;
    int len = 0;
    while(cin >> inp){
        int n = int(inp);
        // cout << inp << endl;
        minChar = min(minChar, n);
        maxChar = max(maxChar, n);
        countChar[inp]++;
        len++;
    }

    long long ans = factor[len];
    long long ans2 = 1;

    for (int i = minChar; i <= maxChar; i++){
        if (countChar[i] != 0){
            // cout << char(i) << ": " << countChar[i] << endl;
            ans2 *= factor[countChar[i]];
            // cout << countChar[i] << endl;
            ans2 %= mod;
            // cout << ans2 << endl;
        }
    }

    ans2 = fastPow(ans2, mod - 2);

    // cout << fastPow(2, 9);

    cout << (ans2 * ans) % mod;


    return 0;
}