// Include the header file for the Employee class.
#include "Employee.h"

// Include the iostream library for console output.
#include <iostream>

// Default constructor for the Employee class.
// It initializes the salary to 0.
Employee::Employee()
{
    salary = 0;
}

// Copy constructor for the Employee class.
// It creates a new instance of the Employee class with the same name and salary as the other instance.
Employee::Employee(const Employee& _other) : Base(_other)
{
    salary = _other.salary;
}

// Copy assignment operator for the Employee class.
// If the current instance is not the same as the other instance,
// it sets the name and salary of the current instance to the name and salary of the other instance.
Employee& Employee::operator=(const Employee& _other)
{
    if (this != &_other)
    {
        Base::operator=(_other);
        salary = _other.salary;
    }
    return *this;
}

// Destructor for the Employee class.
Employee::~Employee()
= default;

void Employee::SetName(const char* name) {
    // Call the SetName method of the Base class
    Base::SetName(name);
}

// Method to set the salary of the Employee object.
void Employee::SetSalary(int _salary)
{
    salary = _salary;
}

// Method to display the record of the Employee object.
// It prints the name and salary of the Employee.
void Employee::DisplayRecord()
{
    std::cout << GetName();
    std::cout << " :: Salary == " << salary << "\n";
}

// Method to clone the Employee object.
// It returns a unique pointer to a new Employee object that is a copy of the current instance.
std::unique_ptr<Base> Employee::clone() const
{
    return std::make_unique<Employee>(*this);
}