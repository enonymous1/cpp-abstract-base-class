// Include the header file for the Base class.
#include "Base.h"

// Include the cstring library for string manipulation functions.
#include <cstring>

// Default constructor for the Base class.
Base::Base()
= default;

// Copy assignment operator for the Base class.
// If the current instance is not the same as the other instance,
// it sets the name of the current instance to the name of the other instance.
Base& Base::operator=(const Base& _other)
{
    if (this != &_other)
    {
        SetName(_other.name);
    }
    return *this;
}

// Copy constructor for the Base class.
// It creates a new instance of the Base class with the same name as the other instance.
Base::Base(const Base& _other)
{
    *this = _other;
}

// Destructor for the Base class.
// It deletes the memory allocated for the name of the instance.
Base::~Base()
{
    delete[] name;
}

// Method to set the name of the Base object.
// It deletes the current name, and if the new name is not null,
// it allocates new memory for the new name and copies the new name into it.
// If the new name is null, it sets the name to null.
void Base::SetName(const char* _name)
{
    delete[] name;
    if (_name != nullptr)
    {
        size_t length = strlen(_name) + 1;
        name = new char[length];
        std::strcpy(name, _name);
    }
    else
    {
        name = nullptr;
    }
}

// Method to get the name of the Base object.
// It returns a pointer to the name of the instance.
char* Base::GetName()
{
    return name;
}