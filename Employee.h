// The header guard prevents the header file from being included more than once.
#pragma once

// Include the header file for the Base class.
#include "Base.h"

// The Employee class is a derived class of the Base class.
class Employee : public Base
{
private:
    // The salary of the Employee.
    int salary = 0;
public:
    // Default constructor for the Employee class.
    Employee();

    // Copy constructor for the Employee class.
    // It creates a new instance of the Employee class with the same name and salary as the other instance.
    Employee(const Employee& _other);

    // Copy assignment operator for the Employee class.
    // If the current instance is not the same as the other instance,
    // it sets the name and salary of the current instance to the name and salary of the other instance.
    Employee& operator=(const Employee& _other);

    // Destructor for the Employee class.
    ~Employee() override;

    void SetName(const char* name) override;

    // Method to set the salary of the Employee object.
    void SetSalary(int _salary);

    // Method to display the record of the Employee object.
    // It prints the name and salary of the Employee.
    void DisplayRecord() override;

    // Method to clone the Employee object.
    // It returns a unique pointer to a new Employee object that is a copy of the current instance.
    std::unique_ptr<Base> clone() const override;
};