#include <iostream>
#include <string>
#include <vector>
#include "Student.hpp"
#include "Assignment.hpp"

using namespace std;

class Gradebook
{
private:
  vector<Student> students;
  vector<Assignment> assignments;

public:
  void addStudent(const string &firstName, const string &lastName, const string &studentID)
  {
    Student newStudent(firstName, lastName, studentID);
    students.push_back(newStudent);
  }

  void addAssignment(const string &name, int totalPoints)
  {
    Assignment newAssignment(name, totalPoints);
    assignments.push_back(newAssignment);
  }

  void inputGrade(const string &studentName, const string &assignmentName, int score)
  {
    for (auto &student : students)
    {
      if (student.FirstName + " " + student.LastName == studentName)
      {
        student.addGrade(assignmentName, score);
        return;
      }
    }
  }

  void printReport() const
  {
    cout << "Last_Name, First_Name, Student_ID";
    for (const auto &assignment : assignments)
    {
      cout << ", " << assignment.name;
    }
    cout << "\n";

    for (const auto &student : students)
    {
      cout << student.LastName << ", " << student.FirstName << ", " << student.studentID;
      for (const auto &assignment : assignments)
      {
        int score = student.getGrade(assignment.name);
        cout << ", " << (score == -1 ? "empty" : to_string(score));
      }
      cout << "\n";
    }
  }

  void assignmentReport(const string &assignmentName) const
  {
    int totalScore = 0;
    int count = 0;

    cout << "Last_Name, First_Name, Student_ID, Score\n";
    for (const auto &student : students)
    {
      int score = student.getGrade(assignmentName);
      cout << student.LastName << ", " << student.FirstName << ", " << student.studentID << ", ";
      if (score == -1)
      {
        cout << "none\n";
      }
      else
      {
        cout << score << "\n";
        totalScore += score;
        count++;
      }
    }

    int maxGrade = 0;
    for (const auto &assignment : assignments)
    {
      if (assignment.name == assignmentName)
      {
        maxGrade = assignment.total_points;
        break;
      }
    }

    double averageScore = count > 0 ? static_cast<double>(totalScore) / count : 0.0;
    cout << "\nAverage score: " << averageScore << " / " << maxGrade << "\n";
  }
};
