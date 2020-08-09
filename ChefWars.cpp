// Chef has a lightsaber which has an attack power denoted by P. He keeps hitting Darth with the lightsaber. 
// Every time he hits, Darth's health decreases by the current attack power of the lightsaber (by P points), 
// and afterwards, P decreases to ⌊P2⌋.
// If the attack power becomes 0 before Darth's health becomes 0 or less, Chef dies. Otherwise, Darth dies. 
// You are given Darth's initial health H and the initial attack power P. Tell Chef if he can beat Darth or 
// if he should escape.
#include<iostream>
using namespace std;
int main()
{
int t;
cin>>t;
  while(t--)
  {  
    int h,p;
    cin>>h>>p; 
    while(p!=0||h!=0)
    {
      if(h>p)
      h-=p;
      else
      h=0;
      p/=2;
    }
    if(h)
    cout<<0<<endl;
    else
    cout<<1<<endl;
   }
}