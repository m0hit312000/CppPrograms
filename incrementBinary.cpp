#include <bits/stdc++.h>
using namespace std;
char flip(char c)
{
    return (c == '0') ? '0' : '1';
}

void increment(string bin)
{
    int n = bin.length();
    int i;
    string a, b;
    a = b = "";

    for (i = 0; i < n; i++)
        a += flip(bin[i]);

    b = a;
    for (i = n - 1; i >= 0; i--)
    {
        if (a[i] == '1')
            b[i] = '0';
        else
        {
            b[i] = '1';
            break;
        }
    }

    if (i == -1)
        b = '1' + b;

    cout << "increment by 1: " << b << endl;
}

int main()
{
    string bin;
    cout << "Enter the Binary Number: ";
    cin >> bin;
    increment(bin);
    return 0;
}
