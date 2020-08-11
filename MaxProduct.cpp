#include<iostream>
#include<vector>
using namespace std;
long long MaxPairwiseProduct(const vector<int>& v ){
    int max1 = -1, max2 = -1;
    int n = v.size();
    for(int i=0;i<n;i++)
    {
       if(( v[i] > v[max1] )||( max1 == -1 ))
       max1 = i;
    }
    for(int i=0;i<n;i++)
    {
       if((i!=max1) && ((v[i] > v[max2]) || (max2 == -1)))
       max2 = i;
    }
    return ((long long)(v[max1])) * (v[max2]);
}

int main()
{
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i]; 
  } 
  cout<<MaxPairwiseProduct(v)<<"\n";
  return 0;
}