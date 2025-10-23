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

///////////
************************************************************************************************************************************************
#include <iostream>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

void multiply3x3(ll A[3][3], ll B[3][3], ll C[3][3]) {
    ll temp[3][3] = {0};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                temp[i][j] = (temp[i][j] + (A[i][k] * B[k][j]) % mod) % mod;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            C[i][j] = temp[i][j];
}

void multiply(ll A[3][3], ll B[3][1], ll C[3][1]) {
    for (int i = 0; i < 3; ++i) {
        C[i][0] = 0;
        for (int k = 0; k < 3; ++k) {
            C[i][0] = (C[i][0] + (A[i][k] * B[k][0]) % mod) % mod;
        }
    }
}

void matrixPower(ll b[3][3], long long a, ll res[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            res[i][j] = (i == j ? 1 : 0);

    ll base[3][3];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            base[i][j] = b[i][j];

    ll temp[3][3];
    while (a > 0) {
        if (a & 1) {
            multiply3x3(res, base, temp);
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    res[i][j] = temp[i][j];
        }
        multiply3x3(base, base, temp);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                base[i][j] = temp[i][j];
        a >>= 1;
    }
}

ll getTribonacci(ll n) {
    if (n == 1) return 0;
    if (n == 2 || n == 3) return 1;

    ll b[3][3] = {
        {1, 1, 1},
        {1, 0, 0},
        {0, 1, 0}
    };

    ll res[3][3];
    matrixPower(b, n - 3, res);

    ll base[3][1] = { {1}, {1}, {0} };
    ll ans[3][1];
    multiply(res, base, ans);

    return ans[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << getTribonacci(n) << "\n";
    }
    return 0;
}

