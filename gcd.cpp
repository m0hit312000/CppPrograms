#include <iostream>

int gcd_naive(int a, int b) {
  
  if(b == 0)
  return a;

  int current_gcd = 1;
    int c = a % b;
    current_gcd = gcd_naive(b,c);
  
  return current_gcd;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}
