// roster.cpp

#include "roster.h"
#include <iostream>
#include <sstream>
#include <vector>

// Constructor: Initializes the classRosterArray with nullptr indicating empty slots
Roster::Roster() {
    for (auto &i : this->classRosterArray) {
        i = nullptr; // Initialize all elements to nullptr
    }
}

// Destructor: Responsible for freeing up the dynamically allocated memory for Student objects
Roster::~Roster() {
    for (auto &i : this->classRosterArray) {
        if (i != nullptr) {
            delete i; // Free allocated memory for each student
            i = nullptr; // Safeguard deleted pointers
        }
    }
}

// Helper function to convert the degree program string to the DegreeProgram enum
DegreeProgram Roster::stringToDegreeProgram(const std::string& degreeProgramString) {
    if (degreeProgramString == "SECURITY") return DegreeProgram::SECURITY;
    else if (degreeProgramString == "NETWORK") return DegreeProgram::NETWORK;
    else if (degreeProgramString == "SOFTWARE") return DegreeProgram::SOFTWARE;
    // Handle error or return a default value
    std::cerr << "Invalid degree program string: " << degreeProgramString << std::endl;
    return DegreeProgram::UNDECIDED;  // Default value or error handling
}

// Add student to the roster by parsing the single string of student data, creates a student object, and adds it
void Roster::add(const std::string& studentData) {
    std::istringstream ss(studentData);
    std::vector<std::string> tokens;
    std::string token;

    // Parse the string into tokens
    while (std::getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    // Check if we have the right amount of data
    if (tokens.size() == 9) {
        std::string studentID = tokens[0];
        std::string firstName = tokens[1];
        std::string lastName = tokens[2];
        std::string emailAddress = tokens[3];
        int age = std::stoi(tokens[4]);
        int daysToComplete1 = std::stoi(tokens[5]);
        int daysToComplete2 = std::stoi(tokens[6]);
        int daysToComplete3 = std::stoi(tokens[7]);
        DegreeProgram degreeProgram = stringToDegreeProgram(tokens[8]);

        // Create daysToComplete array
        int daysToComplete[3] = {daysToComplete1, daysToComplete2, daysToComplete3};

        // Find the first nullptr element in the array to add the new student
        for (int i = 0; i < Roster::numStudents; ++i) {
            if (classRosterArray[i] == nullptr) {
                classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
                lastIndex = i; // Update lastIndex to the newly added student's index
                break; // Exit loop after adding the student
            }
        }
    } else {
        std::cerr << "Error: Incorrect student data format." << std::endl;
    }
}

void Roster::remove(const std::string& studentID) {
    bool found = false;
    for (int i = 0; i < numStudents; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];  // Free the allocated memory for the Student object
            classRosterArray[i] = nullptr;  // Set the pointer to nullptr
            found = true;
            std::cout << "Student with ID " << studentID << " has been removed." << std::endl;
            break;  // Exit the loop after removing the student
        }
    }

    if (!found) {
        std::cout << "Error: Student with ID " << studentID << " not found." << std::endl;
    }
}

void Roster::printAll() {
    Student::printHeader();  // Print the header once at the beginning

    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i] != nullptr) {  // Ensure the student object exists before trying to print
            classRosterArray[i]->print();  // Call the print() method of the Student class
        }
    }
}

// Print average days in course for a student by ID
void Roster::printAverageDaysInCourse(const std::string& studentID) {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            const int* days = classRosterArray[i]->getDaysToComplete();
            std::cout << "Average days in course for student ID " << studentID << ": "
                      << (days[0] + days[1] + days[2]) / 3.0 << std::endl;
            break; // Exit loop after processing the student
        }
    }
}

// Print invalid emails
void Roster::printInvalidEmails() {
    std::cout << "Invalid email addresses:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            std::string email = classRosterArray[i]->getEmailAddress();
            if (email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos) {
                std::cout << email << std::endl;
            }
        }
    }
}

// Print students by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
    }
    std::cout << std::endl;
}