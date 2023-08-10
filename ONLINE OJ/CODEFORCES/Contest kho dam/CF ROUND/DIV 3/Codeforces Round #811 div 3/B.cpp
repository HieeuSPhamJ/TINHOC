#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

const int maxN = 2 * 1e5;
int a[maxN];
map <int,int> countNum;

void printA(){
    for (int i = 1; i <= 5; i++){
        cout << i << ":" << countNum[i] << ' ';
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        countNum.clear();
        int countNeed = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            countNum[a[i]]++;
            if (countNum[a[i]] == 2){
                countNeed++;
            }
        }   

        int count = 0;

        // printA();

        

        while (countNeed > 0){
            // cout << countNeed << "# ";
            // printA();
            count++;
            countNum[a[count]]--;
            if (countNum[a[count]] == 1){
                countNeed--;
            }
        }
        
        cout << count << endl;
    }
    return 0;
}