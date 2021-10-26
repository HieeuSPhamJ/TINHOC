#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    for (int test=1;test<=t;test++){
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        if (x==y) cout<<n<<' '<<n<<endl;
        else{
            int u[5];
            int v[5];
            //1&2
            if (x>y) {
                v[2]=u[1]=n;
                u[2]=v[1]=(n-x)+y;
            }
            else{
                v[2]=u[1]=(n-y)+x;
                u[2]=v[1]=n;
            }
            //3&4
            if (x>y) {
                v[0]=u[3]=0;
                u[0]=v[3]=v[2]-u[2];
            }
            else{
                v[0]=u[3]=u[2]-v[2];
                u[0]=v[3]=0;
            }
            //for (int i=0;i<=4;i++) cout<<u[i]<<' '<<v[i]<<endl;
            //Output
            cout<<u[k%4]<<' '<<v[k%4]<<endl;
        }
    }

    return 0;
}
