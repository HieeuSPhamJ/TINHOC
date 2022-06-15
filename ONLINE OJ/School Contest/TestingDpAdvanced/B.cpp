#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9;

int b[100];
int c[100];

struct matrix
{
    int R,C;
    vector <vector <int>> data;
    matrix(int _R, int _C)
    {
        R=_R;
        C=_C;
        data.resize(R);
        for (int i=0; i<R; i++)
        {
            data[i].resize(C,0);
        }
    }
    matrix operator *(const matrix &other)
    {
        matrix ret(R,other.C);
        for (int i=0; i<R; i++)
        {
            for (int j=0; j<other.C; j++)
            {
                int sum=0;
                for (int k=0; k<C; k++)
                {
                    sum=(sum+(data[i][k]*other.data[k][j])%mod)%mod;
                }
                ret.data[i][j]=sum;
            }
        }
        return ret;
    }
};

matrix power(const matrix &M, int n)
{
    if (n==1)
    {
        return M;
    }
    else
    {
        matrix ret=power(M,n/2);
        ret= ret*ret;
        if (n&1)
        {
            ret=ret*M;
        }
        return ret;
    }
}

void print(matrix a){
    
    for (int i = 0; i < a.data.size(); i++){
        for (int j = 0; j < a.data[i].size(); j++){
            cout << a.data[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "---" << endl;
}

main(){
    int test;
    cin >> test;
    while(test--){
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++){
            cin >> b[i];
        }
        for (int i = 1; i <= k; i++){
            cin >> c[i];
        }
        int n;
        cin >> n;
        if (n <= k){
            cout << b[n];
            cout << endl;
            continue;
        }

        matrix base(k, k);
        for (int i = 0; i < k; i++){
            base.data[i][0] = c[i + 1];
        }
        for (int i = 0; i < k - 1; i++){
            base.data[i][i + 1] = 1;
        }


        matrix a(1, k);

        for (int i = 0; i < k; i++){
            a.data[0][i] = b[k - i];
        }



        // cout << base.data.size() << ' ' << base.data[0].size() << endl;
        // print(a);
        // print(base);
        base = power(base, n-k);
        a = a * base;
        // print(base);
        // print(a);

        cout << a.data[0][0];


        cout << endl;
    }

    return 0;
}


/*
    (a4 a3) => (a5 a4)
    (a4*c1 + a3+c2; a4*1 + a3*0)

    (a4 a3 a2) => (a5 a4 a3)
    (a4*c1 + a3+c2 + a2*c3; a4*1 + a3*0 a2*0; a4*0 + a3*1 a2*0)

*/
