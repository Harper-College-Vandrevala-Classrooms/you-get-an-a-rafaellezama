using namespace std;
#include <string>
class Assignment
{
public:
  string name;
  int total_points;
  Assignment(const string &name, int totalPoints)
      : name(name), total_points(totalPoints) {}
};