#include <iostream>

long long gcd_naive(long long a, long long b) {
  
  if(b == 0)
  return a;

  int current_gcd = 1;
    int c = a % b;
    current_gcd = gcd_naive(b,c);
  
  return current_gcd;
}

long long lcm_naive(long long a, long long b) {
  
  int gcd = gcd_naive(a,b);

  return  ((a * b )/gcd);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
