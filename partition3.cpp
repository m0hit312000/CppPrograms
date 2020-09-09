#include <iostream>
#include <vector>
#include<algorithm>
#include<numeric>

using std::vector;

bool partition3(vector<int>& nums) 
{
    int sum0=accumulate(nums.begin(),nums.end(),0);
    if(sum0%3) return 0;
    //discrete knapsack without repeti 
    int n=nums.size();
    vector<vector<int> > value(sum0/3+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)
    {
        int wi=nums[i-1];
        //cout<<wi<<endl;
        for(int w=1;w<=sum0/3;w++) //all smaller problems
        {
            value[w][i]=value[w][i-1];//if w>wi then it use previous value
            if(w>=wi)
            {
                value[w][i] = std::max(value[w-wi][i-1]+wi,value[w][i-1]);                    
            }
        }
     }
    return value[sum0/3][n]==sum0/3; 
	}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
