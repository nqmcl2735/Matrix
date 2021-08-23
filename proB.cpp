//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task "proB"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int m;
struct matrix {
    ll val[4][4];
    matrix()
    {
        reset(val);
    }
    static matrix mtdv()
    {
        matrix a;
        a.val[1][1] = a.val[2][2] = a.val[3][3] = 1;
        return a;
    }
};
matrix nhan(matrix a, matrix b)
{
    matrix c;
    for (int i = 1; i <= 3; i ++)
        for (int j = 1; j <= 3; j ++)
            for (int k = 1; k <= 3; k ++)
                c.val[i][j] = (c.val[i][j] + a.val[i][k] * b.val[k][j]) % m;
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
int main() {
    ll n;
    cin >> n >> m;
    matrix a;
    for (int i = 1; i <= 3; i ++) a.val[1][i] = 1;
    a.val[2][1] = 1;
    a.val[3][2] = 1;
    matrix b = mu(a, n);
    cout << b.val[1][1] << "\n";
}
