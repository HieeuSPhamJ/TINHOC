#include<bits/stdc++.h>
using namespace std;
int d=0;
void Locso(int n){
int a=-1,b=-1;
int no=n;
while (n>0){
    a=n%10;
    if (a==1 and b==0) {
        cout<<no<<endl;
        d++;
        return;
    }
    b=a;
    n/=10;
}
}

int main (){
    //freopen("number10.inp","r",stdin);
    //freopen("number10.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        int inp;
        cin>>inp;
        Locso(inp);
    }
    if (!d) cout<<-1;
return 0;
}
