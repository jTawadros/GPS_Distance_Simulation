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

double dist(double x1, double y1, double z1, double x2, double y2, double z2);

int main(){
  std::ifstream inFile { "3dsat.txt" };

  std::string val;
  double a,b,c;
  std::vector<sat> satellites {};

  // Create set of satellites
  while(inFile >> val >> a >> b >> c){
    sat temp {};
    temp.name = val;
    temp.x = a;
    temp.y = b;
    temp.z = c;
    satellites.push_back(temp);
  }

  // Request receiver coordinates from user
  double x,y,z;
  std::cout << "Where is the receiver (x y z): ";
  std::cin >> x >> y >> z;

  for(const sat& i : satellites){
    double curr_dist = dist(x,y,z,i.x,i.y,i.z);
    std::cout << "Distance between the receiver at : " << x << "," << y << ',' << z;
    std::cout << " and " << i.name << " at " << i.x << "," << i.y << "," << i.z << " is : \n";
    std::cout << curr_dist << '\n';
  }
  return 0;
}


double dist(double x1, double y1, double z1, double x2, double y2, double z2){
  // parenthesis calculations
  double x = x2-x1;
  double y = y2-y1;
  double z = z2-z1;
  //cmath return distances
  return std::sqrt((x*x)+(y*y)+(z*z));
}
