#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

struct sat {
  std::string name;
  double x;
  double y;
  double z;
};

int main(){
  std::ifstream inFile { "3dsat.txt" };

  std::string val;
  double a,b,c;
  std::vector<sat> satellites {};

  while(inFile >> val >> a >> b >> c){
    sat temp {};
    temp.name = val;
    temp.x = a;
    temp.y = b;
    temp.z = c;
    satellites.push_back(temp);
  }

  for(const sat& i : satellites){
      std::cout << i.name << ' ' << i.x << ' ' << i.y << ' ' << i.z << '\n';
  }
  return 0;
}
