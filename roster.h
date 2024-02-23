//roster.h

#pragma once
#include "student.h"
#include <string>

class Roster {
public:
    Roster(); // Constructor
    ~Roster(); // Destructor

    void add(const std::string& studentData); // Takes a single string to add a student
    void remove(const std::string& studentID);
    void printAll();
    void printAverageDaysInCourse(const std::string& studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    static DegreeProgram stringToDegreeProgram(const std::string& degreeProgramString);

private:
    Student* classRosterArray[5]; // Fixed size array of student pointers
    int lastIndex = -1; // Initialized to -1 to indicate the array is empty
    static const int numStudents = 5; // The number of students
};