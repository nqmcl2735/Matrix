//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define MOD 2021
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
ll n, k;
struct matrix {
    ll val[26][26];
    matrix()
    {
        reset(val);
    }
    static matrix mtdv()
    {
        matrix a;
        for (int i = 1; i <= 25; i ++)
            a.val[i][i] = 1;
        return a;
    }
};
matrix T[4999], A, B, C;
matrix nhan(matrix a, matrix b)
{
    matrix c;
    for (int i = 1; i <= 25; i ++)
        for (int j = 1; j <= 25; j ++)
            for (int x = 1; x <= 25; x ++)
                c.val[i][j] = (c.val[i][j] + a.val[i][x] * b.val[x][j])%MOD;
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
void tinh()
{
    A = B = C = matrix::mtdv();
    for (int i = 2; i <= 4041; i++)
    {
        T[i].val[1][1] = 2;
        for (int j = 2; j <= k; j ++) {
            T[i].val[j][j - 1] = max(i - 2*j + 2, 0);
            T[i].val[j][j] = 2 * j;
        }
    }
    matrix res = matrix::mtdv();
    if (n < 2020)
        for (int i = n; i >= 2; i --)
            res = nhan(res, T[i]);
    else
    {
        ll r = n % 2021;
        for (int i = 2021 + r; i >= 2021; i --)
            A = nhan(A, T[i]);
        for (int i = 2020; i >= 2; i --)
            C = nhan(C, T[i]);
        for (int i = 4041; i >= 2021; i --)
            B = nhan(B, T[i]);
        ll q = (n - 2020)/2021;
            B = mu(B, q);
        res = nhan(A, B);
        res = nhan(res, C);
    }
    cout << res.val[k][1];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    tinh();
}
