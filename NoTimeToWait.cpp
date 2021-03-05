// Only x hours are left for the March Long Challenge and Chef is only left with the last problem unsolved.
//  However, he is sure that he cannot solve the problem in the remaining time. From experience, he figures out that he needs
//  exactly H hours to solve the problem.
// Now Chef finally decides to use his special power which he has gained through years of intense yoga.
// He can travel back in time when he concentrates. Specifically, his power allows him to travel to N different time zones,
// which are T1,T2,…,TN hours respectively behind his current time.
// Find out whether Chef can use one of the available time zones to solve the problem and submit it before the contest ends.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
int main()
{
    int flag = 0;
    ll n, h, x;
    cin >> n >> h >> x;
    ll a[n];
    REP(i, 0, n)
    {
        cin >> a[i];
    }
    REP(i, 0, n)
    {
        if (a[i] + x >= h)
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}