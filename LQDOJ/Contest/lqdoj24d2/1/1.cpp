#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    string str;
    cin>>test;
    while(test--){
        string str;
        cin>>str;
        for (int i=0;i<=str.length()-1;i++){
            int ans=int(str[i]);
            if (ans!=int('u') and ans!=int('e') and ans!=int('o') and ans!=int('a') and ans!=int('i') and ans!=int('U') and ans!=int('E') and ans!=int('O') and ans!=int('A') and ans!=int('I')){
                if (ans > 93)
                    cout<<char(ans);
                else cout<<char(ans+32);
            }
            else{
                if (ans > 93)
                    cout<<char(ans-32);
                else cout<<char(ans);
            }
        }
        cout<<endl;
    }
return 0;
}
