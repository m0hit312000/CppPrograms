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
        ll c, no1 = 0, no2 = 0;
        vi a, b, bin;
        cin >> c;
        while (c > 0)
        {
            bin.push_back(c % 2);
            c = c / 2;
        }
        reverse(bin.begin(), bin.end());
        REP(i, 0, bin.size())
        {
            if (i == 0)
            {
                if (bin[0] == 1)
                {
                    a.push_back(1);
                    b.push_back(0);
                }
                else if (bin[i] == 0)
                {
                    a.push_back(0);
                    b.push_back(0);
                }
            }
            else if (bin[i] == 0)
            {
                a.push_back(1);
                b.push_back(1);
            }
            else if (bin[i] == 1)
            {
                a.push_back(0);
                b.push_back(1);
            }
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        REV(i, a.size() - 1, 0)
        {
            no1 += pow(2, i) * a[i];
        }
        REV(i, b.size() - 1, 0)
        {
            no2 += pow(2, i) * b[i];
        }
        cout << no1 * no2 << "\n";
    }
}