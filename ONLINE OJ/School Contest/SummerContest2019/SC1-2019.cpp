#include<bits/stdc++.h>
using namespace std;


int main(){
    int test;
    cin >> test;
    while(test--){
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        s = " " + s;
        int n = s.size() - 1;
        int temp[11] = {0};
        int sum[11] = {0};
        temp[0] = 3 * n;
        for (int i = 1; i <= n; i++){
            if (s[i] == 'H'){
                temp[i] = 1;
            }
            else if (s[i] == 'T'){
                temp[i] = 3;
            }
            sum[i] = sum[i - 1];
            sum[i] += temp[i];
            // cout << sum << ' ';
            temp[i] = sum[i] + (n - i) * 3;
            // cout << sum[i - 1] << ' ' << sum[i] << ' ' << temp[i] << '\n';

            if (temp[i - 1] < a and sum[i] < a){
                cout << "-";
            }
            else if ((sum[i - 1] >= a and sum[i - 1] < b) and (temp[i - 1] >= a and temp[i - 1] < b)){
                cout << "-";
            }
            else if (sum[i - 1] >= b){
                cout << "-";
            }
            else{
                cout << temp[i];
            }
            cout << '\n';

        }
        if (sum[n] >= b){
            cout << "THANG_HANG";
        }
        else if (sum[n] < b and sum[n] >= a){
            cout << "KHONG_DOI";
        }
        else{
            cout << "XUONG_HANG";
        }
        cout << '\n' << "##########" << '\n';
    }

    return 0;
}