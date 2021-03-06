#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool compareInterval(Segment i1, Segment i2) 
{ 
    return (i1.end < i2.end); 
} 
  

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  std::sort(segments.begin(), segments.end(), compareInterval);
  int point = segments[0].end;
  points.push_back(point);
  for (size_t i = 1; i < segments.size(); ++i) {
    if(point < segments[i].start || point > segments[i].end){
      point = segments[i].end;
      points.push_back(point);
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
