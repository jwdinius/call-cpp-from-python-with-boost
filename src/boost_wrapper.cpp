//! c/c++ system headers
//! other headers
#include <class_def.hpp>
#include <boost/python.hpp>

// create class that will wrap our c++ code into python using boost
struct BoostPyWrapper {
    // we can expose either constructor from class_def, as well
    // as both.  Let's expose both.  This just means that we can init
    // python version using either an input argument or not.
    BoostPyWrapper() : e_(new Exponentiate()) {}
    BoostPyWrapper(double base) : e_(new Exponentiate(base)) {}

    // create a python-callable method to raise base to an input power
    double raise_to_power(double in) {
        return e_->RaiseToPower(in);
    }

    // create a shared pointer to our Exponentiate instance
    boost::shared_ptr<Exponentiate> e_;
};


// define boost python module
BOOST_PYTHON_MODULE(pyRTP) {
    using namespace boost::python;
    // this is where the magic happens
    // here is where we define what is actually exposed to python
    // and how to reference it
    class_<BoostPyWrapper>("Exponentiate", init<>())  // default constructor
        .def(init<double>())  // constructor that takes a single argument
        .def("raise_to_power", &BoostPyWrapper::raise_to_power, "perform the computation");  // ref to our single method

}
