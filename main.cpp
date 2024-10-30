#include <iostream>
#include "student.hpp"
using namespace std;

int main()
{
  gradebook student1;
  student1.f_name = "Rafael";
  student1.l_name = "Lezama";
  cout << student1.f_name << student1.l_name;

  return 0;
}