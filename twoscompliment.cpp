#include <bits/stdc++.h>
using namespace std;
char flip(char c)
{
    return (c == '0') ? '1' : '0';
}

void printTwosComplement(string bin)
{
    int n = bin.length();
    int i;

    string ones, twos;
    ones = twos = "";

    for (i = 0; i < n; i++)
        ones += flip(bin[i]);

    twos = ones;
    for (i = n - 1; i >= 0; i--)
    {
        if (ones[i] == '1')
            twos[i] = '0';
        else
        {
            twos[i] = '1';
            break;
        }
    }
    if (i == -1)
        twos = '1' + twos;

    cout << "2's complement: " << twos << endl;
}
int main()
{
    string bin;
    cout << "Enter the Binary Number: ";
    cin >> bin;
    printTwosComplement(bin);
    return 0;
}
