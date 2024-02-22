// The header guard prevents the header file from being included more than once.
#pragma once

// Include the header file for the Base class.
#include "Base.h"

// The Student class is a derived class of the Base class.
class Student : public Base
{
private:
    // The GPA of the Student.
    float gpa = 0;
public:
    // Default constructor for the Student class.
    Student();

    // Copy constructor for the Student class.
    // It creates a new instance of the Student class with the same name and GPA as the other instance.
    Student(const Student& _other);

    // Copy assignment operator for the Student class.
    // If the current instance is not the same as the other instance,
    // it sets the name and GPA of the current instance to the name and GPA of the other instance.
    Student& operator=(const Student& _other);

    // Destructor for the Student class.
    ~Student() override;

    void SetName(const char* name) override;

    // Method to set the GPA of the Student object.
    void SetGPA(float _gpa);

    // Method to display the record of the Student object.
    // It prints the name and GPA of the Student.
    void DisplayRecord() override;

    // Method to clone the Student object.
    // It returns a unique pointer to a new Student object that is a copy of the current instance.
    std::unique_ptr<Base> clone() const override;
};