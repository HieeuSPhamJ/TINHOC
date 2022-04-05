#include<bits/stdc++.h>
using namespace std;


int main(){
    int test;
    cin >> test;
    while(test--){
        long long a, b, x, y;
        cin >> a >> b >> x >> y;
        int count = 0;
        while(1){
            if (a > b){
                a -= max(x,y);
                b -= min(x,y);
            }
            else{
                b -= max(x,y);
                a -= min(x,y);
            }
            if (a >= 0 and b >= 0){
                count++;
            }
            else{
                break;
            }
        }
        cout << count;
        cout << endl;
    }


    return 0;
}