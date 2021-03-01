#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, max = 0;
    cin >> i >> j;
    int k = i;
    while (k <= j)
    {
        int n = k, count = 0;
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else
            {
                n = 3 * n + 1;
            }
            count++;
        }
        if (count > max)
        {
            max = count;
        }
        k++;
    }
    cout << i << " " << j << " " << max + 1;
}