#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t,i,b=0,no=0;
    cin>>t;
    int a[t];
    for(i=0;i<t;i++)
    {
      cin>>a[i];
    }
    for(i=0;i<t;i++)
    {
        no=0,b=0;
        while(a[i]!=0)
        {
            no = a[i]%10;
            b = (b*10)+no;
            a[i]/=10;
        }
        cout<<b<<endl;
    }
}     