#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,min = 1000000, min2 = -1;
        cin>>n>>k;
        int p[n];
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
        }
        for(int i=0;i<n;i++)
        {
            if(k%p[i] == 0)
            {              
               int temp = k/p[i]-1; 
            //    cout<<v; 
               if(temp < min)
               {
                   min = temp;
                   min2 = p[i];
               }
            }
        }
    
        cout<<min2;        
    }
    // cout<<(6/2);
}