// Include the header file for the Student class.
#include "Student.h"

// Include the iostream library for console output.
#include <iostream>

// Default constructor for the Student class.
// It initializes the GPA to 0.
Student::Student()
{
    gpa = 0;
}

// Copy constructor for the Student class.
// It creates a new instance of the Student class with the same name and GPA as the other instance.
Student::Student(const Student& _other) : Base(_other)
{
    gpa = _other.gpa;
}

// Copy assignment operator for the Student class.
// If the current instance is not the same as the other instance,
// it sets the name and GPA of the current instance to the name and GPA of the other instance.
Student& Student::operator=(const Student& _other)
{
    if (this != &_other)
    {
        Base::operator=(_other);
        gpa = _other.gpa;
    }
    return *this;
}

// Destructor for the Student class.
Student::~Student()
= default;

void Student::SetName(const char* name) {
    // Call the SetName method of the Base class
    Base::SetName(name);
}

// Method to set the GPA of the Student object.
void Student::SetGPA(float _gpa)
{
    gpa = _gpa;
}

// Method to display the record of the Student object.
// It prints the name and GPA of the Student.
void Student::DisplayRecord()
{
    std::cout << GetName();
    std::cout << " :: GPA == " << gpa << "\n";
}

// Method to clone the Student object.
// It returns a unique pointer to a new Student object that is a copy of the current instance.
std::unique_ptr<Base> Student::clone() const
{
    return std::make_unique<Student>(*this);
}