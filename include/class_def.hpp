#pragma once
//! # defines
//! c/c++ system headers
#include <cmath>
//! other headers 
//!(this is where you might put references to the cpp code 
//! you would like to call from python)
class Exponentiate {
 public:
     // if no base value is provided in the constructor, use "e"
     Exponentiate() { base_ = M_E; }
     // constructor takes the base as an argument
     Exponentiate(double base) { base_ = base; }
     // destructor
     ~Exponentiate() {}
     // this class has a single method that raises a base to a power
     double RaiseToPower(double in) { return pow(base_, in); }
 private:
     // class has one private member, the base to raise to some user-input
     // power
     double base_;
};

