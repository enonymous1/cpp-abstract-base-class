// The header guard prevents the header file from being included more than once.
#pragma once

// Include the iostream library for console input and output.
#include <iostream>

// Include the climits library for limits of integral types.
#include <climits>

// Declare a namespace named Header.
namespace Header {

    // Function to clear the input buffer.
    // It clears the error state of the cin object and ignores the maximum number of characters up to '\n'.
    void ClearBuffer() {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
    }

    // Function to get a validated integer from the user.
    // It takes a message to display to the user, and optional minimum and maximum range values.
    // It keeps asking the user for input until a valid integer within the specified range is provided.
    int GetValidatedInt(const char* strMessage, int nMinimumRange = 0, int nMaximumRange = 0) {
        int x;
        while (true) {
            std::cout << strMessage;
            std::cin >> x;
            // If the input operation failed (due to non-numeric input, for example),
            // clear the input buffer and ask for input again.
            while (std::cin.fail())
            {
                ClearBuffer();
                std::cout << "\n\tError, invalid input please try again:  ";
                std::cin >> x;
            }
            ClearBuffer();
            // If no range is specified, or if the input is within the specified range, return the input.
            if ((nMaximumRange == 0 && nMinimumRange == 0) || (x >= nMinimumRange && x <= nMaximumRange))
            {
                return x;
            }
            // If the input is out of range, display an error message and ask for input again.
            std::cout << "\n\tYour input was out of range, lets ride this ride again =)\n\n";
        }
    }
}