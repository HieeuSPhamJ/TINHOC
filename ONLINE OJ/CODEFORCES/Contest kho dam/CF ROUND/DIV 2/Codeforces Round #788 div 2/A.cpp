#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int indexValley = 0;
        int countvalley = 0;
        int last = 1e9;
        int countNegative = 0;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            if (inp < 0){
                countNegative++;
            }
            inp = abs(inp);
            if (last < inp){
                indexValley = i;
                countvalley++;
            }
            last = inp;
        }
        
            if (indexValley < countNegative){
                cout << "NO";
            }
            else{
                cout << "YES";
            }
        }
        cout << countNegative << ' ' << countvalley << ' ' << indexValley;
        cout << "\n";
    }

    return 0;
}