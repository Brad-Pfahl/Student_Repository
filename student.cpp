// student.cpp

#include <iostream>
#include "student.h"

using std::string;
using std::cout;

// Default constructor implementation
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int & day : this->daysToComplete) {
        day = 0; // Initialize each element to 0
    }
    this->degreeProgram = DegreeProgram::UNDECIDED;

}

// Parameterized constructor implementation
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, const int daysToComplete[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; ++i) {
        this->daysToComplete[i] = daysToComplete[i];
    }
    this->degreeProgram = degreeProgram;
}

// Destructor implementation
Student::~Student() {}
    // Clean up resources if any (dynamic memory, file handles, etc.)

// Accessor implementations
string Student::getStudentID() const { return this->studentID; }
string Student::getFirstName() const { return this->firstName; }
string Student::getLastName() const { return this->lastName; }
string Student::getEmailAddress() const {return this->emailAddress; }
int Student::getAge() const {return this->age; }
const int* Student::getDaysToComplete() const {return this->daysToComplete;}
DegreeProgram Student::getDegreeProgram() const {return this->degreeProgram; }


// Mutator implementations
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) {this->firstName = firstName; }
void Student::setLastName(string lastName) {this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) {this->emailAddress = emailAddress; }
void Student::setAge(int age) {this->age = age; }
void Student::setDaysToComplete(int *daysToComplete) {for (int i = 0; i < 3; ++i) {
        this->daysToComplete[i] = daysToComplete[i];
    }}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {this->degreeProgram = degreeProgram; }

// Helper function to convert DegreeProgram enum to string for printing
string Student::degreeProgramToString(DegreeProgram dp) {
    switch(dp) {
        case SECURITY: return "SECURITY";
        case NETWORK: return "NETWORK";
        case SOFTWARE: return "SOFTWARE";
        default: return "UNDECIDED";
    }
}

// print() method implementation
void Student::printHeader() {
    cout << "Output format: StudentID|FirstName|LastName|Email|Age|DegreeProgram\n";
}

void Student::print() const {
    cout << "Student ID: " << studentID << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Email: " << emailAddress << "\t";
    cout << "Age: " << age << "\t";
    cout << "Days in Course: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}\t";
    cout << "Degree Program: " << degreeProgramToString(degreeProgram) << std::endl;
}


