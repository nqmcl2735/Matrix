//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define MOD 666013
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, h, k;
struct matrix {
    ll val[105][105];
    matrix()
    {
        reset(val);
    }
static matrix mtdv()
    {
        matrix a;
        for (int i = 0; i <= h; i ++)
            a.val[i][i] = 1;
        return a;
    }
};
matrix nhan(matrix a, matrix b)
{
    matrix c;
    for (int i = 0; i <= h; i ++)
        for (int j = 0; j <= h; j ++)
            for (int k = 0; k <= h; k ++)
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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> h >> k;
    matrix a;
    for (int i = 0; i <= h; i ++)
        for (int j = 0; j <= h; j ++)
            if (abs(i - j) <= k) a.val[i][j] = 1;
    matrix b = mu(a, n - 1);
    cout << b.val[h][0];
}
