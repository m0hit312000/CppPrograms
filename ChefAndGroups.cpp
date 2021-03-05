// There are N seats in a row. You are given a string S with length N; for each valid i,
// the i-th character of S is '0' if the i-th seat is empty or '1' if there is someone sitting in that seat.

// Two people are friends if they are sitting next to each other. Two friends are always part of the same group
// of friends. Can you find the total number of groups?

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for (int i = a; i < b; i++)
int main()
{
    ll n;
    cin >> n;
    string s[n];
    REP(i, 0, n)
    {
        cin >> s[i];
    }
    REP(i, 0, n)
    {
        int j = 0, grp = 0;
        while (s[i][j] != '\0')
        {
            if (s[i][j] == '1' && s[i][j + 1] != '1')
            {
                grp++;
            }
            j++;
        }
        cout << grp << "\n";
    }
}