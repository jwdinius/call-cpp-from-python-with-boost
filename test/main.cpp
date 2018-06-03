//! c/c++ system headers
#include <cstdio>
#include <iostream>
//! other headers
#include <class_def.hpp>

// c++ interface for testing functionality of custom Exponentiate class
// I will not add rigorous error-handling (e.g. handling non-double command-line args)
// Appropriate input handling is summarized as:
//   0 inputs - default, base = e, power = 1
//   1 input  - base = e, power = input1
//   2 inputs - base = input1, power = input 2
//  >3 inputs - error out
int main(int argc, char **argv) {
    // create a pointer to our yet-to-be-created Exponentiate instance
    Exponentiate *pe;
    // user will (most likely) input the power, check conditional branching below for input handling
    double power;
    if (argc > 3) {
        std::cerr << "Too many input arguments! Expected at most 2 input arguments (base and power)" << std::endl;
        return 1;
    } else if (argc == 3) {
        double base;
        // use sscanf to convert inputs to doubles
        sscanf(argv[1], "%lf", &base);
        sscanf(argv[2], "%lf", &power);
        std::cout << "User entered base = " << base << " and power = " << power << std::endl;
        // use constructor with input
        pe = new Exponentiate(base);
    } else if (argc == 2) {
        // use sscanf to convert input to double
        sscanf(argv[1], "%lf", &power);
        std::cout << "User entered power = " << power << ".  Using e as base." << std::endl;
        // use default constructor
        pe = new Exponentiate();
    } else {
        std::cout << "No inputs entered, defaulting to base = e and power = 1." << std::endl;
        power = 1;
        // default constructor, again
        pe = new Exponentiate();
    }

    // call RaiseToPower from Exponentiate and write result to stdout
    std::cout << "Final answer: base^power = " << pe->RaiseToPower(power) << "." << std::endl;

    // cleanup allocated memory
    delete pe;

    // exit
    return 0;
}
