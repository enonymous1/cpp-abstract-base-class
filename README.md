# PeePs Management System

This project is a simple console-based management system for "PeePs" (People). It's written in C++ and demonstrates the use of object-oriented programming concepts such as inheritance, polymorphism, and smart pointers.

## Files

- `Header.h`: Contains utility functions for input validation and buffer clearing.
- `Base.h`: Defines the abstract base class `Base` from which `Employee` and `Student` classes are derived.
- `Employee.h` and `Student.h`: These are header files for `Employee` and `Student` classes respectively. Both classes inherit from the `Base` class.
- `Employee.cpp` and `Student.cpp`: These are the implementation files for `Employee` and `Student` classes respectively.
- `main.cpp`: Contains the main function and the logic for the management system.

## Classes

- `Base`: An abstract base class that represents a person. It has a virtual destructor and two pure virtual functions: `DisplayRecord()` and `clone()`.
- `Employee`: A derived class from `Base` that represents an employee. It has additional data member `salary` and overrides the `DisplayRecord()` and `clone()` functions from `Base`.
- `Student`: Another derived class from `Base` that represents a student. It has additional data member `gpa` and also overrides the `DisplayRecord()` and `clone()` functions from `Base`.

## Functions

- `AddRecord()`: Adds a new record to the system. The user can choose to add either an `Employee` or a `Student`.
- `DisplayRecords()`: Displays all the records in the system.
- `DuplicateRecord()`: Clones an existing record in the system.

## How to Run

Compile and run the `main.cpp` file. The program will display a menu with four options:

1. Add a peep: This option allows you to add a new record. You can choose to add either an `Employee` or a `Student`.
2. Display all peeps: This option displays all the records in the system.
3. Clone a peep: This option allows you to clone an existing record.
4. Exit: This option exits the program.

## Note

This project uses smart pointers (`std::unique_ptr`) to manage the memory of `Employee` and `Student` objects, ensuring that there are no memory leaks.
