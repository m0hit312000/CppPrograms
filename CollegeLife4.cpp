#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REV(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define vl vector<long long>

ll res(ll n, ll e, ll h, ll a, ll b, ll c)
{
    ll result = 1e15, temp, i = 1;
    if (e >= n * 2)
    {
        result = min(result, n * a);
    }
    if (h >= n * 3)
    {
        result = min(result, n * b);
    }
    if (e >= n && h >= n)
    {
        result = min(result, n * c);
    }
    if (((h - n) / 2 >= 1) && ((h - n) / 2 >= n - e))
    {
        if (b - c < 0)
        {
            temp = min(n - 1, (h - n) / 2);
            result = min(result, temp * (b - c) + n * c);
        }
        else
        {
            temp = max(i, n - e);
            result = min(result, temp * (b - c) + n * c);
        }
    }
    if ((e / 2 >= 1) && (e / 2 >= (3 * n - h + 2) / 3))
    {
        if (a - b < 0)
        {
            temp = min(n - 1, e / 2);
            result = min(result, temp * (a - b) + n * b);
        }
        else
        {
            temp = max(i, (3 * n - h + 2) / 3);
            result = min(result, temp * (a - b) + n * b);
        }
    }
    if (((e - n) >= 1) && ((e - n) >= n - h))
    {
        if (a - c < 0)
        {
            temp = min(n - 1, e - n);
            result = min(result, temp * (a - c) + n * c);
        }
        else
        {
            temp = max(i, n - h);
            result = min(result, temp * (a - c) + n * c);
        }
    }
    if (n >= 3 && e >= 3 && h >= 4)
    {
        result = min(result, a + b + c + res(n - 3, e - 3, h - 4, a, b, c));
    }
    return result;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, e, h, a, b, c, price = 0, flag = 1, min1, min2;
        cin >> n >> e >> h >> a >> b >> c;
        ll result = res(n, e, h, a, b, c);
        if (result < 1e15)
        {
            cout << result << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
}