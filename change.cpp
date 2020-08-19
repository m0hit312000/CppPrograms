#include <iostream>

int get_change(int m) {
  //write your code here
  int n=0;
  while(m > 0){
    if(m >= 10){
      n++;
      m-=10;
    }
    else if(m >= 5){
      n++;
      m-=5;
    }
    else if(m >= 1){
      n++;
      m-=1;
    }
  }

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
