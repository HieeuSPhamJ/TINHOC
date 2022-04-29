#include<bits/stdc++.h>
using namespace std;

const int maxN = 100010;

int a[maxN];
int dp[maxN] = {0};

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0] = 0;
    int maxLen = 0;
    for (int i = 1; i <= n; i++){
        if (a[dp[maxLen]] < a[i]){
            maxLen++;
            dp[maxLen] = i;
        }
        else{
            int left = 0;
            int right = maxLen;
            while(left <= right){
                int mid = (left + right) / 2;
                if (a[dp[mid]] < a[i]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            dp[left + 1] = i;
        }
    }
    cout << maxLen;

    return 0;
}