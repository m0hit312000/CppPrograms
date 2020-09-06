#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n = w.size();
  int bag[n+1][W+1];

  for(int i = 0; i <= n; i++) {
    bag[i][0] = 0;
  }

  for(int j = 0; j <= W; j++) { 
    bag[0][j] = 0;
  }
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= W; j++) {
      if(j - w[i-1] >= 0)
       bag[i][j] = std::max(bag[i - 1][j], bag[i - 1][j - w[i - 1]] + w[i-1]);   
      else
       bag[i][j] = bag[i-1][j];
    }
  }

  return bag[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
