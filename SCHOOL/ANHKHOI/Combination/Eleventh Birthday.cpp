#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

struct dataType{
    int diff;
    int len;
    dataType(int a, int b){
        diff = a;
        len = b;
    }

}

const int maxN = 2010;
int dp[2000][11];


main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            string s;
            cin >> s;
            int temp = 0;
            for (int i = 0; i < s.size(); i += 2){
                temp += s[i] - '0';
            }
            for (int i = 1; i < s.size(); i += 2){
                temp -= s[i] - '0';
            }
            dataType inp(temp, 1);
            dataType inp(temp, -1);

        }


    }
    

    return 0;
}


