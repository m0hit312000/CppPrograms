#include <iostream>

int get_change(int m) {
  //write your code here
  int coin[] = {1,3,4};
  int MinCoin[m];
  MinCoin[0] = 0;
  for(int i = 1; i <= m; i++) {
    MinCoin[i] = 10000;
    for(int j = 0; j < 3; j++) {
      if(i >= coin[j]) {
        int NumCoin = MinCoin[i-coin[j]] + 1;
        if(NumCoin < MinCoin[i]) {
          MinCoin[i] = NumCoin;
        }
      }
    }
  }  
  return MinCoin[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
