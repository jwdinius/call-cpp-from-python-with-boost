//! c/c++ system headers
//! other headers
#include <class_def.hpp>
#include <boost/python.hpp>

struct BoostPyWrapper {
    BoostPyWrapper() : dc_(new DummyClass()) { }
    ~BoostPyWrapper() { }

    double calculate(double in) {
        return dc_->calculate(in);
    }

    boost::shared_ptr<DummyClass> dc_;
};


BOOST_PYTHON_MODULE(pydummy) {
    PyEval_InitThreads();

    using namespace boost::python;

    class_<BoostPyWrapper>("DummyClass", init<>()) // was init<>()
        .def("calculate", &BoostPyWrapper::calculate, "perform the computation");

}
