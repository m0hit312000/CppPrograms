#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REV(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define vl vector<long long>
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, val, add = 0;
        int flag = 0;
        cin >> n;
        vi a, p;
        REP(i, 0, n)
        {
            cin >> val;
            a.push_back(val);
        }
        sort(a.begin(), a.end());
        REP(i, 1, n + 1)
        {
            p.push_back(i);
        }
        REP(i, 0, n)
        {
            if (a[i] > p[i])
            {
                flag = 1;
                break;
            }
            else
            {
                add += abs(a[i] - p[i]);
                if (add % 2 == 0)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }
        }

        if (flag)
        {
            cout << "SECOND\n";
        }
        else
        {
            cout << "FIRST\n";
        }
    }
}