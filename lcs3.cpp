#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &d) {
  //write your code here
  int l1 = a.size(), l2 = b.size(), l3 = d.size();
  int L[l1+1][l2+1][l3+1];
  for (int i=0; i<=l1; i++) 
  { 
    for (int j=0; j<=l2; j++) 
    { 
      for (int k=0; k<=l3; k++) 
      { 
         if (i == 0 || j == 0||k==0) 
          L[i][j][k] = 0; 
         else if (a[i-1] == b[j-1] && a[i-1]==d[k-1]) 
          L[i][j][k] = L[i-1][j-1][k-1] + 1; 
         else
          L[i][j][k] = std::max(std::max(L[i-1][j][k], L[i][j-1][k]), L[i][j][k-1]); 
      } 
    } 
  }
  return L[l1][l2][l3];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
