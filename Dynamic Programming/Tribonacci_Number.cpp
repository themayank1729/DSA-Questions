#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

vector<vector<ll>> multiply(vector<vector<ll>> &A, vector<vector<ll>> &B,
                            int p, int q, int m, int n)
{
    vector<vector<ll>> C(p, vector<ll>(n, 0));

    for (int i = 0; i < p; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < q; ++k)
            {
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % mod) % mod;
            }
        }
    }
    return C;
}

vector<vector<ll>> matrixPower(vector<vector<ll>> b, long long a)
{
    int n = b.size();

    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i)
        res[i][i] = 1;

    while (a > 0)
    {
        if (a & 1)
            res = multiply(res, b, n, n, n, n);
        b = multiply(b, b, n, n, n, n);
        a >>= 1;
    }

    return res;
}

ll getTribonacci(ll n)
{
    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;

    vector<vector<ll>> b = {
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0}};

    vector<vector<ll>> res = matrixPower(b, n - 3);

    vector<vector<ll>> base = {
        {1},
        {1},
        {0}};

    vector<vector<ll>> ans = multiply(res, base, 3, 3, 3, 1);

    return ans[0][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << getTribonacci(n) << "\n";
    }
    return 0;
}
