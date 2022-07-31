#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        map <char,int> checkCount;
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++){
            char inp;
            cin >> inp;
            if (checkCount[inp] == 0){
                sum += 2;
                checkCount[inp]++;
            }
            else{
                sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}