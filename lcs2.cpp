#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int l1 = a.size(), l2 = b.size();
  int longSubSeq[l1+1][l2+1];
   
   //longSubSeq[i,j] will hold the LCS of str1 (0 to i-1) and str2 (0 to j-1)
   for (int i=0; i<=l1; i++) {
      for (int j=0; j<=l2; j++) {
         if (i == 0 || j == 0)
            longSubSeq[i][j] = 0;
         else if (a[i-1] == b[j-1])
            longSubSeq[i][j] = longSubSeq[i-1][j-1] + 1;
         else
            longSubSeq[i][j] = std::max(longSubSeq[i-1][j], longSubSeq[i][j-1]);
      }
   }
   return longSubSeq[l1][l2];
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
