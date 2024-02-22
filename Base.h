#pragma once

#include <memory>

// The Base class is an abstract class that serves as a base for other classes.
class Base
{
private:
    // The name of the Base object, stored as a pointer to a character array.
    char* name = nullptr;

public:
    // Default constructor for the Base class.
    Base();

    // Copy constructor for the Base class.
    Base(const Base& _other);

    // Copy assignment operator for the Base class.
    Base& operator=(const Base& _other);

    // Virtual destructor for the Base class.
    virtual ~Base();

    // Method to set the name of the Base object.
    virtual void SetName(const char* name) = 0;

    // Method to get the name of the Base object.
    char* GetName();

    // Pure virtual function to display the record of the Base object.
    // This function must be implemented by any class that inherits from Base.
    virtual void DisplayRecord() = 0;

    // Pure virtual function to clone the Base object.
    // This function must be implemented by any class that inherits from Base.
    virtual std::unique_ptr<Base> clone() const = 0;
};