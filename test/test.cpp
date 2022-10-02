#include <bits/stdc++.h>

#define X first
#define Y second
#define int long long

using namespace std;
const int N = 1e6 + 3;
const long long base = 256;
typedef pair <long long, long long> ii;
const ii mod = ii(1e9 + 7, 998244353);

string A, B;
ii hashb;
ii Pow[N], sum[N];

ii mul(ii x, ii y)
{
    ii res;
    res.X = (x.X * y.Y) % mod.X;
    res.Y = (x.Y * y.Y) % mod.Y;
    return res;
}

ii add(ii x, ii y)
{
    ii res;
    res.X = (x.X + y.Y) % mod.X;
    res.Y = (x.Y + y.Y) % mod.Y;
    return res;
}

ii sub(ii x, ii y)
{
    ii res;
    res.X = ((x.X - y.Y) % mod.X + mod.X) % mod.X;
    res.Y = ((x.Y - y.Y) % mod.Y + mod.Y) % mod.Y;
    return res;
}

void Init()
{
    Pow[0] = ii(1, 1);
    for (int i = 1; i < N; ++ i)
    {
        Pow[i] = mul(Pow[i - 1], ii(base, base));
    }
}

ii getHash(int l, int r)
{
//    sum[r] - sum[l - 1] * base ^ (r - l + 1);
    cout << "*" << sum[r].X << ' ' << sum[l - 1].X << ' ' << Pow[r - l + 1].X << endl;
    return sub(sum[r], mul(sum[l - 1], Pow[r - l + 1]));
}

main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;
    Init();
    hashb = ii(0, 0);
    for (int i = 0; i < B.length(); ++ i)
    {
        hashb = add(mul(hashb, ii(base, base)), ii(B[i], B[i]));
    }
    sum[0] = ii(0, 0);
    A = '$' + A;
    for (int i = 1; i < A.length(); ++ i)
    {
//        cout << A[i] << endl;
        sum[i] = add(mul(sum[i - 1], ii(base, base)), ii(A[i], A[i]));
    }
//    cout << "*" << hashb.X << ' ' << hashb.Y << endl;
    for (int i = 1; i < A.length(); ++ i)
    {
        cout << sum[i].X << ' ' << sum[i].Y << endl;
    }
    cout << endl;
    cout << getHash(3, 4).X;
//    for (int i = B.length(); i < A.length(); ++ i)
//    {
//        cout << i << ' ' << getHash(i - B.length() + 1, i).X << ' ' << hashb.X<< endl;
//        if (hashb == getHash(i - B.length() + 1, i))
//        {
////            cout << i - B.length() + 1 << ' ';
//        }
//    }

    for (int i = 1; i <= A.length(); i++){
        cout << sum[i].X << " ";
    }
    return 0;
}