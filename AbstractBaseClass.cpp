// Include the necessary libraries and header files.
#include <iostream>
#include <vector>
#include <memory>
#include "Header.h"
#include "Base.h"
#include "Employee.h"
#include "Student.h"

// Use the namespace defined in Header.h.
using namespace Header;

// Define an enumeration for the different choices in the main menu.
enum class Choice {
    Add = 1,
    Display,
    Clone,
    Exit
};

// Function prototypes.
void AddRecord(std::vector<std::unique_ptr<Base>>& v);
void DisplayRecords(const std::vector<std::unique_ptr<Base>>& v);
void DuplicateRecord(std::vector<std::unique_ptr<Base>>& v);

// The main function.
int main()
{
    // Vector to store the records of Base objects.
    std::vector<std::unique_ptr<Base>> peeps;
    Choice choice;

    // Main loop.
    do
    {
        // Display the main menu.
        std::cout << "------------------------PeePs Management------------------------\n";
        char mainMenu[] = "\n\t\t1) Add a peep\n\t\t2) Display all peeps\n\t\t3) Clone a peep\n\t\t4) Exit\n\n\tSelection: ";
        choice = static_cast<Choice>(GetValidatedInt(mainMenu, 1, 4));

        // Perform the selected action.
        switch (choice)
        {
            case Choice::Add:
                AddRecord(peeps);
                break;
            case Choice::Display:
                DisplayRecords(peeps);
                break;
            case Choice::Clone:
                DuplicateRecord(peeps);
                break;
            default:
                break;
        }
    } while (choice != Choice::Exit);

    std::cout << std::endl;
    std::cin.get();
    return 0;
}

// Function to add a record.
void AddRecord(std::vector<std::unique_ptr<Base>>& v)
{
    // Ask the user for the type of record to add.
    std::cout << "------------------------What kind of peep?------------------------\n";
    char mainMenu[] = "\n\t\t1) Employee\n\t\t2) Student\n\n\tSelection: ";
    int mainMenuChoice = GetValidatedInt(mainMenu, 1, 2);

    // Add an Employee record.
    if (mainMenuChoice == 1)
    {
        auto e = std::make_unique<Employee>();
        std::cout << "------------------------Name?------------------------\n\t\tName:  ";
        char name[25];
        std::cin.get(name, 25);
        std::cin.ignore(INT_MAX, '\n');
        e->SetName(name);
        int salary = GetValidatedInt("\n------------------------Salary?------------------------\n\t\tSalary:  ");
        e->SetSalary(salary);
        v.push_back(std::move(e));
    }
        // Add a Student record.
    else
    {
        auto s = std::make_unique<Student>();
        std::cout << "------------------------Name?------------------------\n\t\tName:  ";
        char name[25];
        std::cin.get(name, 25);
        std::cin.ignore(INT_MAX, '\n');
        s->SetName(name);
        auto gpa = (float)GetValidatedInt("\n------------------------GPA?------------------------\n\t\tGPA:  ");
        s->SetGPA(gpa);
        v.push_back(std::move(s));
    }
}

// Function to display all records.
void DisplayRecords(const std::vector<std::unique_ptr<Base>>& v)
{
    // Print the header.
    std::cout << "------------------------Display Records------------------------\n";

    // Loop through the vector and display each record.
    for (const auto& record : v)
    {
        std::cout << "\n\t\t";
        record->DisplayRecord();
    }

    std::cout << "\n";
}

// Function to duplicate a record.
void DuplicateRecord(std::vector<std::unique_ptr<Base>>& v)
{
    // Check if there are any records to duplicate.
    if (v.empty())
    {
        std::cout << "Sorry NO peeps FOUND!!!  Add PEEPS!\n";
        return;
    }

    // Ask the user for the record to duplicate.
    std::cout << "------------------------Clone Zone------------------------\n\t\t";
    std::cout << "There are " << v.size() << " peeps in the records, choose one to clone.\n\t\t";
    int choice = GetValidatedInt("Peep number: ", 1 , v.size());

    // Duplicate the selected record.
    v.push_back(v[choice - 1]->clone());
}