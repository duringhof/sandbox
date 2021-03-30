#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::string;

typedef std::pair<int, int> point;
typedef std::vector<point> points;

point str2point(string s) {

  int x, y;
  char sep;
  std::istringstream iss(s);

  iss >> sep;
  iss >> x;
  iss >> sep;
  iss >> y;
  iss >> sep;
  
  point output = std::make_pair(x, y);

  return output;
}

std::vector<point> str2points(string s) {

  int x, y;
  char sep;
  points output;
  std::istringstream iss(s);

  while (!iss.eof()) {
    iss >> sep;
    iss >> x;
    iss >> sep;
    iss >> y;
    iss >> sep;
    iss >> sep;
    output.push_back(std::make_pair(x, y));
  }
  
  return output;
}

int main() {

  string str_testpoint = "(33523,5    )";
  string str_testpoints = "(4,6), (1,2), (3,2), (7,9), (24,327)";

  points testpoints = str2points(str_testpoints);

  for (auto itr : testpoints) {
    
    std::cout << "x = " << itr.first << " - y = " << itr.second << std::endl;
  }
  

  return 0;
}