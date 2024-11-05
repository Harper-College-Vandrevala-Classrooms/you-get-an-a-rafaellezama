#include <string>
#include <vector>
using namespace std;

class Student
{
public:
  string FirstName;
  string LastName;
  string studentID;
  vector<string> assignmentNames;
  vector<int> scores;

  Student(const string &firstName, const string &lastName, const string &studentID)
      : FirstName(firstName), LastName(lastName), studentID(studentID) {} // Corrected initialization

  void addGrade(const string &assignmentName, int score)
  {
    for (size_t i = 0; i < assignmentNames.size(); ++i)
    {
      if (assignmentNames[i] == assignmentName)
      {
        scores[i] = score;
        return;
      }
    }
    assignmentNames.push_back(assignmentName);
    scores.push_back(score);
  }

  int getGrade(const string &assignmentName) const
  {
    for (size_t i = 0; i < assignmentNames.size(); ++i)
    {
      if (assignmentNames[i] == assignmentName)
      {
        return scores[i];
      }
    }
    return -1;
  }
};
