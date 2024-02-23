// student.h


#pragma once
#include <string>
#include <iomanip>
#include "degree.h"

using std::string;

class Student {
public:
    // Constructors and Destructor
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, const int daysToComplete[], DegreeProgram degreeProgram);
    ~Student();

    // Accessors (getters)
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    const int* getDaysToComplete() const;
    DegreeProgram getDegreeProgram() const;

    // Mutators (setters)
    void setStudentID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysToComplete(int daysToComplete[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // Helper function to convert DegreeProgram enum to string for printing
    [[nodiscard]] static string degreeProgramToString(DegreeProgram dp) ;

    static void printHeader(); /*displays a header for the data to follow*/
    void print() const; /*displays 'this' student's data*/

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[3];
    DegreeProgram degreeProgram;

};