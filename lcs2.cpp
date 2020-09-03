#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int l1 = a.size(), l2 = b.size();
  int c[l1][l2];
  for(int i = 0; i <= l1; i++) {
    c[i][0] = 0;
  }
  for(int j = 0; j <= l2; j++) {
    c[0][j] = 0;
  }
  for(int j = 1; j <= l1; j++) {  
    for(int i = 1; i <= l2; i++) {
      if(a[j-1] == b[i-1])
       c[j][i] = 1 + c[j-1][i-1];
      else if(a[j-1] != b[i-1])
       c[j][i] = std::max(c[j][i-1], c[j-1][i]); 
    }
  }
  return c[l1][l2];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
