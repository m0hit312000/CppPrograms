#include <iostream>
#include <string>
#include<algorithm>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int l1 = str1.length(), l2 = str2.length(), track, t;              
  int dist[100][100];
  for(int i = 0; i < l1; i++) {
     dist[0][i] = i;  
  }
  for(int j = 0; j < l2; j++) {
     dist[j][0] = j;  
  }                   
  for(int j = 1; j <= l1; j++) {
    for(int i = 1; i <= l2; i++) {
      if(str1[i-1] == str2[j-1]) {
        track = 0;
      }
      else {
        track = 1;
      }
      t = std::min((dist[i-1][j]+1), (dist[i][j-1]+1));
      dist[i][j] = std::min(t, (dist[i-1][j-1] + track));
    }
  }

  return dist[l2][l1];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
