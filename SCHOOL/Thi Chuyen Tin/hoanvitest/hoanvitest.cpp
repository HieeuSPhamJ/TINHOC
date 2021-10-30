#include <bits/stdc++.h>
using namespace std;
int main() {
int a[3]={1,2,3};
do{
    cout<<a[0]<<a[1]<<a[2]<<endl;
}
while ( next_permutation(a,a+3) );
return 0;
}
