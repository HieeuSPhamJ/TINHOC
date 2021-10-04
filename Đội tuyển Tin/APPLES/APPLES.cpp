#include <bits/stdc++.h>
using namespace std;

int a[1000010][3];
int n;

int count(int b,int m){
    int s1=0;
    int s2=0;
    for(int i=0;i<n;i++){
        if (a[i][b]<m)
            s1++;
        if (a[i][b]>m)
            s2++;
    }
        return !(s1==s2);

}

int main(){
    freopen("APPLES.inp","r",stdin);
    freopen("APPLES.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
    // for(int i=0;i<n;i++) cout<<a[i][0]<<' '<<a[i][1];
    // cout<<endl;
    for(int i=0;i<n;i++)
        for (int j=i+1;j<n;j++){
            if (a[i][0]==a[j][0] )
                // if (countx(0,a[i][0],n)==0){
                //         cout<<'#';
                //         cout<<i+1<<' '<<j+1;
                //         return 0;
                // }

                if (count(0,a[i][0])==0){
                	// cout<<'#';
                    cout<<i+1<<' '<<j+1;
                    return 0;
            }
            if (a[i][1]==a[j][1] )
                if (count(1,a[i][1])==0){
                	// cout<<'#';
                    cout<<i+1<<" "<<j+1;

                    return 0;
            }
        }
    return 0;
}