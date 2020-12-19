#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;

int optimal_weight(int W, const vector<int> &w){
    // use 1-D array from n to (n - weight) to fill the array
    vector<int> c(W+1);
    for(int i = 0; i < w.size(); ++i){
        for(int j = W; j >= w[i]; --j){
            // in this problem, cost and weight is equal
            c[j] = std::max(c[j], c[j-w[i]] + w[i]);
        }
    }
    // c[W] is the maximum value of knapsack with W weight
    return c[W];
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
