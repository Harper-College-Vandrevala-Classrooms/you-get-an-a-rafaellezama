#include <iostream>
#include "gradebook.hpp"
using namespace std;

int main()
{
  Gradebook gradebook;

  gradebook.addStudent("Bob", "Bobberson", "ABC123");
  gradebook.addStudent("Sam", "Sammerson", "DEF456");
  gradebook.addStudent("Jess", "Jesserson", "HIJ789");

  gradebook.addAssignment("Quiz 1", 100);
  gradebook.addAssignment("Lab 1", 50);

  gradebook.inputGrade("Sam Sammerson", "Quiz 1", 95);
  gradebook.inputGrade("Bob Bobberson", "Quiz 1", 85);
  gradebook.inputGrade("Jess Jesserson", "Lab 1", 49);
  gradebook.inputGrade("Jess Jesserson", "Quiz 1", 93);
  gradebook.inputGrade("Bob Bobberson", "Lab 1", 0);

  cout << "Full Gradebook Report:\n";
  gradebook.printReport();

  cout << "\nAssignment Report for Lab 1:\n";
  gradebook.assignmentReport("Lab 1");

  return 0;
}