#include<bits/stdc++.h>
using namespace std;

int a[1003];


int main(){
    int n;
    int testcase = 1;
    cin >> n;
    while (n != 0){
        cout << "Case " << testcase++ << ":" << endl;
        vector <int> sumList;

        for (int i = 1; i <= n; i++){
            cin >> a[i];
            // cout << a[i] << ' ';
        }
        for (int i = 1; i <= n; i++){
            for (int e = i + 1; e <= n; e++){
                sumList.push_back(a[i] + a[e]);
                // cout << a[i] + a[e] << ' ';
            }
        }
        sort(sumList.begin(),sumList.end());
        // cout << endl;
        int test;
        cin >> test;
        while (test--){
            int inp;
            cin >> inp;
            // cout << inp << endl;
            int ans = -1;
            if (sumList[sumList.size() - 1] <= inp){
                ans = sumList[sumList.size() - 1];
            }
            else{
                for (int i = 1; i < sumList.size(); i++){
                    if (inp < sumList[i]){
                        if (abs(sumList[i] - inp) < abs(inp - sumList[i - 1])){
                            ans = sumList[i];
                        }
                        else{
                            ans = sumList[i - 1];
                        }
                        break;
                    }
                }
            }
            
            cout << "Closest sum to " << inp << " is " << ans << ".";
            cout << endl;
        }
        cin >> n;
    }

    return 0;
}