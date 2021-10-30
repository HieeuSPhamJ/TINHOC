#include <bits/stdc++.h>
using namespace std;
int x[100];
int ok[100];
int n;

void lk(int i) {
    for (int j=1;j<=n;j++) {
        if (ok[j]==0) {
            x[i]=j; ok[j]=1;
            if (i==n) {
                for (int e=1;e<=n;e++)  cout<<x[e];
                    cout<<endl;
                }
                    else
                        lk(i+1);
            ok[j]=0;
        }
    }
}

int main() {
memset(ok,0,sizeof(ok));
cin>>n;
lk(1);
return 0;
}
