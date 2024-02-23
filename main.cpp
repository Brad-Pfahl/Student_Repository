// main.cpp


#include "roster.h"
#include <iostream>

int main() {

    // Print course title, programming language, student ID, and name
    std::cout << "Course Title: Scripting and Programming - Applications - C867\nProgramming Language: C++\nStudent ID: 011070820\nName: Brad Pfahl\n";

    // Add students to roster
    const string studentData[] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Brad,Pfahl,bpfahl@wgu.edu,29,14,20,30,SOFTWARE"
    };

    const int numStudents = 5;
    Roster classRoster;

    // Demonstrate functionality

    // Add each student to classRoster using the single-string add method
    for (int i = 0; i < numStudents; i++) {
        classRoster.add(studentData[i]);
    }

    // Display all students
    std::cout << "Displaying all students in roster" << std::endl;
    classRoster.printAll();
    std::cout << std::endl;

    // Display invalid emails
    std::cout << "Displaying students with invalid emails" << std::endl;
    classRoster.printInvalidEmails();
    std::cout << std::endl;

    // Display average days in course for each student
    std::cout << "Displaying average days in course: " << std::endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster.printAverageDaysInCourse(studentData[i].substr(0, studentData[i].find(',')));
    }
    std::cout << "\n";

    // Display students by degree program: SOFTWARE
    std::cout << "Displaying by Degree Program: SOFTWARE" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    std::cout << "\n";

    // Remove Student with ID:A3
    std::cout << "Removing Student with ID 'A3'" << std::endl;
    classRoster.remove("A3");
    std::cout << std::endl;

    //Show that Student with ID:A3 is removed
    std::cout << "Displaying all students in roster" << std::endl;
    classRoster.printAll();
    std::cout << std::endl;

    //Display Error for trying to remove student that is not there
    std::cout << "Removing Student with ID 'A3'" << std::endl;
    classRoster.remove("A3");
    std::cout << std::endl;


    return 0;
}