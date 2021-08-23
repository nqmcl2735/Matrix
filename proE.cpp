//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define MOD 1000000007
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task "proE"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
ll n, k, x;
ll d[105];
struct matrix {
    ll val[103][103];
    matrix()
    {
        reset(val);
    }
    static matrix mtdv()
    {
        matrix a;
        for (int i = 0; i <= 100; i ++)
            a.val[i][i] = 1;
        return a;
    }
};
matrix nhan(matrix a, matrix b)
{
    matrix c;
    for (int i = 0; i <= 100; i ++)
        for (int j = 0; j <= 100; j ++)
            for (int k = 0; k <= 100; k ++)
                c.val[i][j] = (c.val[i][j] + a.val[i][k] * b.val[k][j]) % MOD;
    return c;
}

matrix mu (matrix a, ll n)
{
    matrix b = matrix::mtdv();
    if(n == 0) return b;
    matrix c = mu(a, n/2);
    b = nhan(c, c);
    if (n % 2) b = nhan (b, a);
    return b;
}
void nhap() {
    cin >> n >> k;
    while (n --)
    {
        cin >> x;
        d[x] ++;
    }
    matrix a;
    a.val[0][0] = 1;
    for (int i = 1; i <= 100; i ++) a.val[0][i] = a.val[1][i] = d[i];
    for (int i = 2; i <= 100; i ++) a.val[i][i - 1] = 1;
    matrix b = mu (a, k);
    cout << b.val[0][0] + b.val[0][1];
}
int main() {
    nhap();
}
