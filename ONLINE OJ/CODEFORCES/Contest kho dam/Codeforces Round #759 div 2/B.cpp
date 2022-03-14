#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        int a[200005];
        cin >> n;
        int maxIndex = 1;
        int maxA = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (a[maxIndex] < a[i]){
                maxIndex = i;
            }
            maxA = max(maxA, a[i]);
        }

        a[0] = maxA + 1;

        int count = 0;

        while (a[n] < maxA){
            int i = maxIndex;
            for (i = maxIndex; a[i] < a[n]; i++){
                continue;
            }
            swap(a[i - 1], a[maxIndex]);
            for (; a[i] < a[n]; i++){
                continue;
            }
            swap(a[i - 1], a[maxIndex]);
            for (i = n - 1; a[i] > a[n]; i--){
                continue;
            }
            swap(a[i], a[n]);

            count++;
        }
        
        cout << count;

        cout << endl;
    }

    return 0;
}