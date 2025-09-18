#include <bits/stdc++.h>
using namespace std;

int solve(string N, int B)
{
    int sum = 0;
    for (int i = 0; i < N.size(); ++i)
    {
        int power = N.size() - i - 1;
        char ch = N[i];
        int mul;
        if ('0' <= ch && ch <= '9')
            mul = ch - '0';
        else
            mul = ch - '7';
        if (mul >= B)
            return -1;
        sum = sum + (mul * pow(B, power));
    }
    return sum;
}

int main()
{
    int tt = 1;
    // cin>>tt;
    while (tt--)
    {
        cout << solve("A2C", 14);
    }
}

